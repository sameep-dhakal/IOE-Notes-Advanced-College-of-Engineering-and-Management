import Pyro4   # python remote object = pyro

# Replace with the actual URI of the server
uri = "PYRO:obj_4a5eeb0ce4b74e178daa26fdb05a3107@localhost:42519"

server = Pyro4.Proxy(uri)

print(server.getMessage())
