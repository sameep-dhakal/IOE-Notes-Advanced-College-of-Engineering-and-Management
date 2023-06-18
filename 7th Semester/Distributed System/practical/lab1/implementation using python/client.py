# client.py
import xmlrpc.client

client = xmlrpc.client.ServerProxy("http://localhost:8000/")

print("Client ready, type and press Enter key")

while True:

    print("\nEnter operation to perform (add, sub, mul, div): ")
    operation = input().lower()
    if operation == "exit":
        break
    print("Enter first parameter: ")
    param1 = int(input())
    print("Enter second parameter: ")
    param2 = int(input())

    if operation == "add":
        result = client.add(param1, param2)
    elif operation == "sub":
        result = client.subtract(param1, param2)
    elif operation == "mul":
        result = client.multiply(param1, param2)
    elif operation == "div":
        result = client.divide(param1, param2)
    else:
        print("Invalid operation")
        continue

    print("Result:", result)
