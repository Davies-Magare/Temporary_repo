#!/usr/bin/python3
import cmd
from models.base_model import BaseModel
from models.engine.file_storage import FileStorage
import models

class HBNBCommand(cmd.Cmd):
    """The console implementation"""

    prompt = '(hbnb) '

    def validate(self, line, creat_flag=0):
        """Validates the user input"""
        args = line.split(' ')
        if len(values) == 0:
            print ("** class name missing **")
        elif args[0] not in globals():
                print("** class doesn't exist **")
        elif len(args) < 2 and not creat_flag:
                    print("** instance id missing **")
        elif len(args) >= 2:
            key = "{}.{}".format(args[0], args[1])
            objs = models.storage.reload()
            if key not in objs.keys():
                print("** no instance found **")
                return False
        return True

    def do_create(self, line):
        """ Creates an object """
        if self.validate(line, 1):
            class_name = line.split(' ')
            obj = eval("{}()".format(class_name[0]))
            obj.save()
            print(obj.id)

    def do_empty_line(self, line):
        """Handles the empty line"""

        if not line:
            pass

    def do_quit(self, line):
        """Quits the interpreter"""

        return True

    def do_EOF(self, line):
        """Handles the end of file"""

        return True

if __name__ == '__main__':
    HBNBCommand().cmdloop()
