#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

struct Data
{
	unsigned long data;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
	private:
		Serializer(void);
		Serializer(unsigned long data);
		Serializer(const Serializer& other);
		~Serializer(void);

		Serializer& operator=(const Serializer& other);
};

#endif
