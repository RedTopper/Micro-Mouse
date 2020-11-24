import requests


class MouseRequest(object):
	url = ''

	def setUrl(self, url):
		self.url = url
		requests.get(url + "link")


	def MoveRight(self):
		requests.get('http://' + self.url + '5000/move/right')
		return


	def MoveLeft(self):
		requests.get('http://' + self.url + '5000/move/left')


	def MoveForward(self):
		requests.get('http://' + self.url + '5000/move/forward')


	def MoveBackward(self):
		requests.get('http://' + self.url + '5000/move/back')
