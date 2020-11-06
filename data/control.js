function log(message) {
	let console = document.getElementById("console");
	let wrapper = document.createElement("div");
	let text = document.createTextNode(message);
	wrapper.appendChild(text);
	console.appendChild(wrapper);
}

let socket = new WebSocket("ws://172.16.0.1/ws");

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