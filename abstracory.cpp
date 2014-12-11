// abstract_factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace System;

ref class Film {
public:
	String^ language;
	virtual String^ getLanguage() = 0;
};

ref class ChineseFilm : Film {
public:
	ChineseFilm(){
	language = "Chinese";
	}
	virtual String^ getLanguage() override { return language; }
};

ref class UsaFilm : Film {
	
public:
	UsaFilm(){
	language = "English";
	}
	virtual String^ getLanguage() override { return language; }
};

ref class Factory{
public:
	virtual Film^ produce() = NULL;	
};

ref class ChinaFactory : Factory{
public:
	virtual Film^ produce() override {
		Film^ film = gcnew ChineseFilm();
		return film;
	}	
};

ref class UsaFactory : Factory{
public:
	virtual Film^ produce() override {
		Film^ film = gcnew UsaFilm();
		return film;
	}	
};

ref class FactoryMaker {
private:
	String^ location;
public:
	FactoryMaker(String^ loc){ 
		location = loc;
	}
	Factory^ getFactory(){
		if(!String::Compare(location,"USA"))
			return gcnew UsaFactory();
		else
			return gcnew ChinaFactory();
	}
	~FactoryMaker(){;}
};


int _tmain(int argc, _TCHAR* argv[])
{
	String^ location = "USA";
	FactoryMaker^ myFactoryMaker = gcnew FactoryMaker(location);
	Console::WriteLine(location);
	Console::WriteLine("we have produced film with language : ");
	Console::WriteLine(myFactoryMaker->getFactory()->produce()->getLanguage());
	Console::ReadLine();
	return 0;
}
