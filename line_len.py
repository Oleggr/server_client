# check line length for content length

line = "<html><head><title>Hello</title></head><body><form method=\"post\">str_param:<input maxlength=\"25\" size=\"40\" name=\"str_param\"/>token:<input maxlength=\"25\" size=\"40\" name=\"token\"/><br><input name=\"\" type=\"submit\" value=\"send\"/></form></body></html>"
counter = 0

for symbol in line:
	print(symbol)
	counter += 1

print("counter =", counter)