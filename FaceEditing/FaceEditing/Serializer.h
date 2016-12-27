#include"Common.h"

#include"cereal\archives\binary.hpp"

class CLC_RECORD
{
public:

	CLC_RECORD() :a(20), m_root("good"){}

	CLC_RECORD(const  CLC_RECORD& m_record){

		*this = m_record;
	}

	CLC_RECORD& operator=(const  CLC_RECORD& m_record)
	{
		a = m_record.a;
		m_root.assign(m_record.m_root);

		return *this;
	}


public:

	int a;
	std::string m_root;

};



template<typename T>
class CLC_DATA{

public:

	CLC_DATA(){}
	CLC_DATA(const T& data) :m_data(data){}

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(m_data); // serialize things by passing them to the archive
	}


public:
	T m_data;
};

template<typename T>
class Serializer
{
public:
	Serializer(const std::string& filename = "./data.dat"):m_filename(filename){
	
	
	};
	~Serializer(){};

	bool Archive(const T& data){

		m_out_stream.open(m_filename, std::ios::binary);

		cereal::BinaryOutputArchive out_archive(m_out_stream);

		CLC_DATA<T> m_datum(data);

		out_archive(m_datum);

		m_out_stream.close();

		return true;
	}

	bool Elicit(T& data){

		m_in_stream.open(m_filename, std::ios::binary);

		cereal::BinaryInputArchive in_archive(m_in_stream);

		CLC_DATA<T> m_datum;
		
		in_archive(m_datum);

		data = m_datum.m_data; // need  to implement Copy Assignment

		m_in_stream.close();

		return true;
	}

private:
	std::string m_filename;
	
	std::ofstream m_out_stream;
	std::ifstream m_in_stream;
	
	

};

