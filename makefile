PhoneNumber.o:
	g++ PhoneNumber.cpp -o PhoneNumber.o

FormatNumber.o:
	g++ FormatNumber.cpp -o FormatNumber.o

test:
	g++ -o FormatNumberTest FormatNumber.cpp ValidateNumber.cpp PhoneNumber.cpp FormatNumberTest.cpp -lcppunit && echo running tests && ./FormatNumberTest

all:
	echo todo
