# check line length for content length

#line = "<html><head><title>Error</title></head><body>Uncorrect request type. Only GET and POST are acceptable.</body></html>"
# line = "<html><head><title>Authorized</title></head><body>Token value is correct</body></html>"

line = "HTTP/1.1 200 OK\r\nContent-Type: text/html;\r\nConnection: close\r\n\r\n<html><head><title>Authorized</title></head><body>Token value is correct<br>Current str param value:<br>Current int param value:</body></html>"

# str_param=124&token=token_value
# '''

counter = 0

for symbol in line:
	print(symbol)
	counter += 1

print("counter =", counter)
