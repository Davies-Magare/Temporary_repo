"""File storage module"""
import json
from models.base_model import BaseModel

class FileStorage:
    """The file storage class"""

    __file_path = "storage.json"
    __objects = {}

    def all(self):
        """Returns the dictionary of objects"""

        return self.__objects

    def new(self, obj):
        """Adds an objects to the objects dictionary"""

        key = "{}.{}".format(obj.__class__.__name__, obj.id)
        self.__objects[key] = obj

    def save(self):
        """Serializes the instances using json and stores them in a file"""
        objs_dict = {}
        with open(self.__file_path, 'w') as f:
            for key, value in self.__objects.items():
                objs_dict[key] = BaseModel.to_dict(value)
            f.write(json.dumps(objs_dict))

    def reload(self):
        """Reloads the instances from the file"""
        try:
            with open(self.__file_path, 'r') as f:
                json_string = f.read()
                new_dict = {}
                if (json_string):
                    objects = json.loads(json_string)
                    for key, value in objects.items():
                        class_name, id = key.split('.')
                        new_dict[key] = eval("{}(**value)".format(class_name))
                self.__objects = new_dict
        except Exception:
            pass

        except Exception:
            pass


