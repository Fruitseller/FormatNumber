test:
	g++ -o FormatNumberTest FormatNumber.cpp ValidateNumber.cpp PhoneNumber.cpp FormatNumberTest.cpp -lcppunit && echo running tests && ./FormatNumberTest

all:
	echo todo
