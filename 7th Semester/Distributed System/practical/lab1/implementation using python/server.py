# server.py
from xmlrpc.server import SimpleXMLRPCServer


class Calculator:

    def add(self, a, b):
        return a + b

    def multiply(self, a, b):
        return a * b

    def divide(self, a, b):
        return a / b


server = SimpleXMLRPCServer(("localhost", 8000))
server.register_instance(Calculator())
print("Server running...")
server.serve_forever()
#  b):
#         return a + b

#     def multiply(self, a, b):
#         return a * b

#     def divide(self, a, b):
#         return a / b


# server=SimpleXMLRPCServer(("localhost", 8000))
# server.register_instance(Calculator())
# print("Server running...")
# server.serve_forever()
