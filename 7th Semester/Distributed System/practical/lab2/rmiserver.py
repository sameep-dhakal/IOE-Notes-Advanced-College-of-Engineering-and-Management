import Pyro4

@Pyro4.expose
class RmiServer(object):
    MESSAGE = "Hello World"

    def getMessage(self):
        return self.MESSAGE

daemon = Pyro4.Daemon()
uri = daemon.register(RmiServer)

print("RMI server started")
print("URI: ", uri)

daemon.requestLoop()