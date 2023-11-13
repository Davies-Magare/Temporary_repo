import cmd
import os

class HelloWorld(cmd.Cmd):
	"""Simple command processor example"""

	def do_greet(self, person):
		"""greet [person]
		Greet the named person"""
		if person:
			print('hello, {}'.format(person))
		else:
			print("hello")
	def do_add(self, x, y):
		return x + y
	def do_EOF(self, line):
		return True	

if __name__ == '__main__':
	HelloWorld().cmdloop()
	
	
