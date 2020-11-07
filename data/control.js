function log(message) {
	let console = document.getElementById("console");
	let wrapper = document.createElement("div");
	let text = document.createTextNode(message);
	wrapper.appendChild(text);
	console.appendChild(wrapper);
}

let socket = new WebSocket("ws://172.16.0.1/ws");
let gp = null;

socket.onopen = function(e) {
	let greet = {
		"hello": "hello"
	};

	socket.send(JSON.stringify(greet));
	log("Opened connection!");
};

socket.onmessage = function(event) {
	log(event.data);
};

socket.onclose = function(event) {
	if (event.wasClean) {
		log("Server closed connection!");
	} else {
		log("Connection died!");
	}
};

socket.onerror = function(error) {
	log("Error: " + error.message);
};

function set(left, right) {
	let motors = {
		"left": left,
		"right": right
	};

	socket.send(JSON.stringify(motors));
}

window.addEventListener("gamepadconnected", function(e)
{
	gp = navigator.getGamepads()[0];
	console.log("game pad connected" + gp.axes)
});

setInterval(function() {
	if(!gp)  return;
	gp = navigator.getGamepads()[0];
	var left = Math.abs(gp.axes[1]) > 0.1 ? gp.axes[1] : 0;
	var right = Math.abs(gp.axes[3]) > 0.1 ? gp.axes[3] : 0;
	// console.log("Left: " + left + " " + "Right: " + right);
	set(left, right);
}, 1000);
