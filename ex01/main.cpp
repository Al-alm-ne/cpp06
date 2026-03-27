#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main()
{
	std::cout << BWHT << "\n=== Basic Serialization/Deserialization ===" << NC << "\n";
	{
		Data original;
		original.str = "First Test";
		
		std::cout << BCYN << "Original Data address: " << &original << NC << "\n";
		std::cout << BYEL << "Original Data content: " << original.str << NC << "\n";
		
		uintptr_t raw = Serializer::serializer(&original);
		std::cout << BMAG << "Serialized value: " << raw << "\n";
		
		Data* deserialized = Serializer::deserializer(raw);
		std::cout << BCYN << "Deserialized address: " << deserialized << "\n";
		std::cout << BYEL << "Deserialized content: " << deserialized->str << "\n";
		
		if (deserialized == &original)
			std::cout << BCYN << "Addresses match!" << "\n";
		else
			std::cout << BRED << "Addresses don't match!" << "\n";
			
		if (deserialized->str == original.str)
			std::cout << BYEL << "Content matches!" << "\n";
		else
			std::cout << BRED << "Content doesn't match!" << "\n";
	}
	
	std::cout << BWHT << "\n=== Multiple Data Objects ===" << "\n";
	{
		Data data1, data2, data3;
		data1.str = "First";
		data2.str = "Second";
		data3.str = "Third";
		
		uintptr_t raw1 = Serializer::serializer(&data1);
		uintptr_t raw2 = Serializer::serializer(&data2);
		uintptr_t raw3 = Serializer::serializer(&data3);
		
		std::cout << BMAG << "Serialized values: " << raw1 << ", " << raw2 << ", " << raw3 << "\n";
		
		Data* recovered1 = Serializer::deserializer(raw1);
		Data* recovered2 = Serializer::deserializer(raw2);
		Data* recovered3 = Serializer::deserializer(raw3);
		
		std::cout << BYEL << "Recovered: " << recovered1->str << ", " 
				  << recovered2->str << ", " << recovered3->str << "\n";
		
		if (recovered1 == &data1 && recovered2 == &data2 && recovered3 == &data3)
			std::cout << BCYN << "All addresses match!" << "\n";
		else
			std::cout << BRED << "Some addresses don't match!" << "\n";
	}
	
	std::cout << BWHT << "\n=== Empty Data ===" << "\n";
	{
		Data empty;
		std::cout << BYEL << "Empty string: '" << empty.str << "'" << "\n";
		
		uintptr_t raw = Serializer::serializer(&empty);
		Data* recovered = Serializer::deserializer(raw);
		
		if (recovered == &empty)
			std::cout << BCYN << "Empty data serialization works!" << "\n";
		else
			std::cout << BRED << "Empty data serialization failed!" << "\n";
	}
	
	std::cout << BWHT << "\n=== Chain Serialization ===" << "\n";
	{
		Data original;
		original.str = "Chain test";
		
		// Multiple serialize/deserialize cycles
		uintptr_t raw1 = Serializer::serializer(&original);
		Data* ptr1 = Serializer::deserializer(raw1);
		uintptr_t raw2 = Serializer::serializer(ptr1);
		Data* ptr2 = Serializer::deserializer(raw2);
		
		std::cout << BYEL << "Original: " << &original << "\n";
		std::cout << "After cycle 1: " << ptr1 << "\n";
		std::cout << "After cycle 2: " << ptr2 << "\n";
		
		if (ptr2 == &original && ptr2->str == original.str)
			std::cout << BCYN << "Chain serialization maintains integrity!" << "\n";
		else
			std::cout << BRED << "Chain serialization failed!" << "\n";
	}
	
	std::cout << BWHT << "\n=== Complex String ===" << "\n";
	{
		Data data;
		data.str = "Complex string with numbers 12345 and symbols !@#$%^&*()";
		
		uintptr_t raw = Serializer::serializer(&data);
		std::cout << raw << "\n";
		Data* recovered = Serializer::deserializer(raw);
		
		std::cout << BCYN << "Original: " << data.str << "\n";
		std::cout << BYEL << "Recovered: " << recovered->str << "\n";
		
		if (recovered == &data && recovered->str == data.str)
			std::cout << BCYN << "Complex string preserved!" << NC << "\n";
		else
			std::cout << BRED << "Complex string lost!" << NC << "\n";
	}
	std::cout << "\n";
	return 0;
}