import uuid
from datetime import datetime
import models

"""
The base model module
"""


class BaseModel:
    """The parent class from which other classes
        inherit
    """

    def __init__(self, *args, **kwargs):
        if kwargs:
            for key, value in kwargs.items():
                if key in ('created_at', 'updated_at'):
                    setattr(self, key, datetime.strptime(value, '%Y-%m-%dT%H:%M:%S.%f'))
                elif key != '__class__':
                    setattr(self, key, value)
        else:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = datetime.now()
            models.storage.new(self)

    def __str__(self):
        """Returns the string representation of the object"""

        return "[{}] ({}) {}".format(self.__class__.__name__, self.id, self.__dict__)

    def save(self):
        self.updated_at = datetime.now()
        models.storage.save()

    def to_dict(self):
        self.created_at = (self.created_at).isoformat()
        self.updated_at = (self.updated_at).isoformat()
        data = self.__dict__
        data['__class__'] = self.__class__.__name__
        return data




