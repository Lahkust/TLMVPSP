/* En-tête du programme
====================
Programme :	list.h
Auteur:	Christopher Brown
Date dernière modification :  2016/12/15
Description :	Class list selon la structure d'une list avec des méthodes comme insert et erase. 
				Elle contient la class iterator qui permet de se situer dans la liste.
To Do :
*/

#pragma once
#include <assert.h>

template <typename TYPE> class list;

//CELLULE
template <typename TYPE>
class cellule
{
	friend class list<TYPE>;	//la seule classe ayant accès à la 
								//représentation de la cellule
	TYPE element;				//Contenu de la cellule
	cellule <TYPE> *next;		//Pointeur vers la cellule suivante 
	cellule <TYPE> *previous;	//Pointeur vers la cellule precedente

	cellule(const TYPE &e, cellule<TYPE> *n = NULL, cellule<TYPE> *p = NULL)
	{
		element = e;
		next = n;
		previous = p;
	}
};

//LIST
template <typename TYPE>
class list
{
private:
	cellule <TYPE> *_first;		//Adresse du premier élément 

public:
	//CLASS ITERATOR
	class iterator
	{
		friend class list<TYPE>;
	private:
		cellule<TYPE>* 	_current;	//adresse de la cellule
		const list<TYPE>* _list;	//adresse de la liste
	public:
		iterator();					//constructeurs
		~iterator();				//destructeur

		const iterator& operator=(const iterator& I);//pour j=i

		bool operator==(const iterator& I)const; //pour if(j==i)
		bool operator!=(const iterator& I)const; //pour if(j!=i)

		iterator operator++(int i);		//i++
		const iterator& operator++();	//++i

		iterator operator--(int i);		//i--
		const iterator& operator--();	//--i

		TYPE& operator*();				//accès à un élément
		const TYPE& operator*()const;	//idem, en mode const

	};
	list(void); 
	~list(void);

	//list(const list<TYPE> &l) = delete;	//Copieur désactivé

	void clear();	   
	bool empty()const; 

	iterator begin()const;	//return premier
	iterator end()const;	//return NULL

	iterator insert(iterator I, const TYPE& e); 	//inséré un élément selon iterator
	iterator erase(iterator I); 					//enlever un élément selon l'iterateur
	iterator erase(iterator first, iterator last); 	//supprimé plusieurs éléments selon deux iterateurs

	TYPE& operator[](iterator I);					//pas ds la STL
	const TYPE& operator[](iterator I)const; 		//chercher dans la liste l’élément reçu en paramètre
													//et à partir de l’itérateur reçu pour la version 2
													//la méthode  retourne un iterator sur l’element trouvé
													//s’il est innexistant, l’iterator est à la fin 
	
	iterator operator()(const TYPE& i)const;  				//recherche dans la liste un élément spécifique
	iterator operator()(const TYPE& i, iterator I)const; 	//recherche dans la liste un élément spécifique

	const list<TYPE>& operator=(const list<TYPE>& l); 		//list source = list en paramètre
};

/*MÉTHODE ITERATOR*/

template <typename TYPE>
list<TYPE>::iterator::iterator()
{
	_current = nullptr;
	_list = nullptr;
}

template <typename TYPE>
list<TYPE>::iterator::~iterator()
{
	_current = nullptr;
	_list = nullptr;
}

//pour j=i
template <typename TYPE>
const typename list<TYPE>::iterator &list<TYPE>::iterator::operator=(const iterator& I)
{
	_current = I._current;
	_list = I._list;

	return *this;
}

//pour if(j==i)
template <typename TYPE>
bool list<TYPE>::iterator::operator==(const iterator& I)const
{
	return I._current == _current;	
}

//pour if(j!=i)
template <typename TYPE>
bool list<TYPE>::iterator::operator!=(const iterator& I)const
{
	return I._current != _current;
}

//i++
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::iterator::operator++(int i)
{
	assert(_current != nullptr);
	list<TYPE>::iterator temp(*this);
	_current = _current->next;

	return temp;
}

//++i
template <typename TYPE>
const typename list<TYPE>::iterator& list<TYPE>::iterator::operator++()
{
	assert(_current != nullptr);
	_current = _current->next;

	return *this;
}

//i--
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::iterator::operator--(int i)
{
	assert(_list->_first != nullptr);
	list<TYPE>::iterator temp(*this);
	if (_current == nullptr)
		_current = _list->_first->previous;
	else
		_current = _current->previous;

	return temp;
}

//--i
template <typename TYPE>
const typename list<TYPE>::iterator& list<TYPE>::iterator::operator--()
{
	assert(_list->_first != nullptr);
	if (_current == nullptr)
		_current = _list->_first->previous;
	else
		_current = _current->previous;

	return *this;
}

//accès à un élément
template <typename TYPE>
TYPE& list<TYPE>::iterator::operator*()
{
	assert(_list != nullptr && _current != nullptr && _list->_first != nullptr);
	return _current->element;
}

//idem, en mode const
template <typename TYPE>
const TYPE& list<TYPE>::iterator::operator*()const
{
	assert(_list != nullptr && _current != nullptr && _list->_first != nullptr);
	return _current->element;
}

/*MÉTHODE LISTE*/

template <typename TYPE>
list<TYPE>::list(void)
{
	_first = nullptr;
}

template <typename TYPE>
list<TYPE>::~list(void)
{
	clear();
}

//supprimé les éléments de la liste
template <typename TYPE>
void list<TYPE>::clear()
{
	list<TYPE>::iterator it;
	it = begin();

	while (!empty())
	{
		it = erase(it);
	}	
	_first = nullptr;
}

//vérifie sur la liste est vide
template <typename TYPE>
bool list<TYPE>::empty()const
{
	if (_first == nullptr)
		return true;
	return false;
}

//return premier
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::begin()const
{
	list<TYPE>::iterator it;
	it._current = _first;
	it._list = this;

	return it;
}

//returns NULL
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::end()const
{
	list<TYPE>::iterator it;
	it._current = nullptr;
	it._list = this;

	return it;
}

//inséré un élément selon iterator
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::insert(iterator I, const TYPE& e)
{
	assert(I._list == this);
	if (empty()) 						//insére la 1ere cellule
		I._current=_first->previous
					=_first
					=new cellule<TYPE>(e, nullptr, nullptr);

	else if (I._current == _first) 		//insére au début, avant la 1ere
		I._current = _first 
					= I._current->previous 
					= new cellule<TYPE>(e, I._current, I._current->previous);

	else if (I._current == nullptr) 	//insére à la fin (push_back)
		I._current = _first->previous 
					= _first->previous->next 
					= new cellule<TYPE>(e, nullptr, _first->previous);

	else 								//cas général
		I._current =I._current->previous
					=I._current->previous->next
					=new cellule<TYPE>(e, I._current, I._current->previous);

	return I;
}

//enlever un élément selon l'iterateur
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::erase(iterator I)
{
	assert(I._list == this);
	assert(I._current != nullptr);
	assert(!empty());
	
	list<TYPE>::iterator temp;
	temp._list = I._list;

	if (_first->next != nullptr) {					
		if (_first == I._current) { 				//première cellule
			_first = temp._current = I._current->next;
			temp._current->previous = I._current->previous;
		}

		else if (I._current->next == nullptr) {		//dernière cellule
			_first->previous = temp._current = I._current->previous;
			temp._current->next = nullptr;
		}
		else {										//cas general
			temp._current = I._current->next;
			temp._current->previous = I._current->previous;
			temp._current->previous->next = temp._current;
		}
	}
	else
		_first = nullptr;

	delete I._current;
	return temp;
}

//supprimé plusieurs éléments selon deux iterateurs
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::erase(iterator first, iterator last)
{
	assert(first != end());
	while (first._current->next != nullptr && first != last)
		first = erase(first);
	first = erase(first);

	return first;
}

//chercher dans la liste
template <typename TYPE>
TYPE& list<TYPE>::operator[](iterator I)
{
	list<TYPE>::iterator it;
	it = I;

	return it._current->element;
}

//chercher dans la liste l’élément reçu en paramètre et à partir de l’itérateur reçu pour la version 2
//la méthode  retourne un iterator sur l’element trouvé s’il est innexistant, l’iterator est à la fin
template <typename TYPE>
const TYPE& list<TYPE>::operator[](iterator I)const
{
	return I._current->element;
}

//recherche dans la liste un élément spécifique
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::operator()(const TYPE& i)const
{
	list<TYPE>::iterator it;

	if (!empty())
	{
		it = begin();
		while (it != end())
		{
			if (it._current->element == i)
				return it;
			it++;
		}
	}
	it = end();
	return it;
}

//recherche dans la liste un élément spécifique
template <typename TYPE>
typename list<TYPE>::iterator list<TYPE>::operator()(const TYPE& i, iterator I)const
{
	if (!empty())
	{
		I = begin();
		while (it != end())
		{
			if (I._current->element == i)
				return I;
			I++;
		}
	}
	I = end();
	return I;
}

//makes source list = to parameter list returns list for chaining
template <typename TYPE>
const list<TYPE>& list<TYPE>::operator=(const list<TYPE>& l)
{
	list<TYPE>::iterator it;
	list<TYPE>::iterator itL;
	it = begin();
	itL = l.begin();

	if (this == &l)
		return *this;

	clear();

	if (l.empty())
		return *this;
	
	while (itL != l.end())
	{
		insert(it,itL._current->element);
		itL++;
	}

	return *this;
}