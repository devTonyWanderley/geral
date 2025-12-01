/**
 * @date    Início 29/11/25 10:37
 * @brief   Agrupar estruturas de dados gabarito com ligação singular
 */
#ifndef EDGABARITO_H
#define EDGABARITO_H

#include <QDebug>

template <class T>
class No
{
public:
    No<T> *Segue;
    T Valor;
    No()
    {
        Segue = nullptr;
        Valor = T();
    }

    /*
    No(T &arg)
    {
        Segue = nullptr;
        Valor = T(arg);
    }*/

    No(const T& arg)
    {
        Segue = nullptr;
        Valor = T(arg);
    }
};

template <class T>
class Lista
{
public:
    No<T> *Frente;
    No<T> *Fundo;
    No<T> *Atual;
    uint Count;
    uint CAtual;

    Lista()
    {
        Frente = Fundo = Atual = nullptr;
        Count = CAtual = 0;
    }

    void PushFront(const T& arg)
    {
        No<T> *aponta = new No<T>(arg);
        if(Fundo)
        {
            aponta->Segue = Frente;
            Frente = aponta;
        }
        else Frente = Fundo = aponta;
        Count++;
    }

    void PushBack(const T& arg)
    {
        No<T> *aponta = new No<T>(arg);
        if(Fundo)
        {
            Fundo->Segue = aponta;
            Fundo = aponta;
        }
        else Frente = Fundo = aponta;
        Count++;
    }

    bool PopFront(T &var)
    {
        if(!Frente) return false;
        No<T> *aponta = Frente;
        var = Frente->Valor;
        Frente = Frente->Segue;
        delete aponta;
        Count--;
        return true;
    }

    bool PopBack(T &var)
    {
        if(!Fundo) return false;
        if(Count == 1)
        {
            No<T> *aponta = Fundo;
            var = aponta->Valor;
            Frente = Fundo = nullptr;
            delete aponta;
            Count--;
            return true;
        }
        var = Fundo->Valor;
        No<T> *aponta = Frente;
        while(aponta->Segue != Fundo) aponta = aponta->Segue;
        Fundo = aponta;
        aponta = aponta->Segue;
        delete aponta;
        Count--;
        return true;
    }

    bool GetFront(T &var)
    {
        if(!Frente) return false;
        var = Frente->Valor;
        return true;
    }

    bool GetBack(T &var)
    {
        if(!Fundo) return false;
        var = Fundo->Valor;
        return true;
    }

    bool GetN(T &var, const uint n)
    {
        if(Count < n) return false;
        if(CAtual > n || !Atual)
        {
            Atual = Frente;
            CAtual = 1;
        }
        while(CAtual < n)
        {
            Atual = Atual->Segue;
            CAtual++;
        }
        var = Atual->Valor;
        return true;
    }

    uint Length()
    {
        return Count;
    }
};

template <class T>
class Fila
{
private:
    Lista<T> lst;
public:
    Fila()
    {}

    void Push(const T& arg)
    {
        lst.PushBack(arg);
    }

    bool Pop(T &var)
    {
        return lst.PopFront(var);
    }

    bool Primo(T &var)
    {
        return lst.GetFront(var);
    }

    uint Lenght()
    {
        return lst.Length();
    }
};

template <class T>
class Pilha
{
private:
    Lista<T> lst;
public:
    Pilha()
    {}

    void Push(const T& arg)
    {
        lst.PushFront(arg);
    }

    bool Pop(T &var)
    {
        return lst.PopFront(var);
    }

    bool Top(T &var)
    {
        return lst.GetFront(var);
    }

    uint Lenght()
    {
        return lst.Length();
    }
};

#endif // EDGABARITO_H
