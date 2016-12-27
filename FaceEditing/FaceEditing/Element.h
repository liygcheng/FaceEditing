#pragma once 
#include"Common.h"
template<typename T1,typename T2>
class AbstractElement // base class
{
public:
	AbstractElement(){}
	~AbstractElement(){
		if (static_cast<void*>(m_element) != NULL)
			delete m_element;
	};

	virtual bool constructElement(T2 t2) = 0;
	virtual void show(void)= 0; //
	virtual bool archive(const std::string dumpName = "dumpName") = 0;
	virtual bool elicit(const std::string dumpName = "dumpName")  = 0;

protected:
	T1* m_element;
	
};

template<typename T1, typename T2>
class FaceGeometry :public AbstractElement < T1, T2> {

public:
	FaceGeometry(){}

	virtual bool constructElement(T2 t2){

		return true;
	}
	virtual void show(void){
	
		
	}
	virtual bool archive(const std::string dumpName = "dumpName")
	{
		
		return true;
	}
	virtual bool elicit(const std::string dumpName = "dumpName")
	{
		return true;
	}
};

template<typename T1, typename T2>
class FaceAlbedo :public AbstractElement < T1, T2 > {
public:
	FaceAlbedo(){}

	virtual bool constructElement(T2 t2){

		return true;
	}
	virtual void show(void){


	}
	virtual bool archive(const std::string dumpName = "dumpName")
	{

		return true;
	}
	virtual bool elicit(const std::string dumpName = "dumpName")
	{
		return true;
	}


};

template<typename T1, typename T2>
class FaceIllumination :public AbstractElement < T1, T2 > {
public:
	FaceIllumination(){}

	virtual bool constructElement(T2 t2){

		return true;
	}
	virtual void show(void){


	}
	virtual bool archive(const std::string dumpName = "dumpName")
	{

		return true;
	}
	virtual bool elicit(const std::string dumpName = "dumpName")
	{
		return true;
	}


};