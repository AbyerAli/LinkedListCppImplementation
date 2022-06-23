#include <iostream>
using namespace std;

class PassengerInfo
{
    int id;
    int ticketNumber;
    string name;

public:
    PassengerInfo() {}
    PassengerInfo(int id, int ticketNumber, string name)
    {
        this->id = id;
        this->ticketNumber = ticketNumber;
        this->name = name;
    }
    int getId()
    {
        return this->id;
    }
    void displayPassengerInfo()
    {
        cout << "\nPassenger Info:" << endl;
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "Ticket Number: " << this->ticketNumber << endl;
    }
};

class Passenger
{
public:
    PassengerInfo PassengerObj;
    Passenger *next;
    Passenger()
    {
        next = NULL;
    }
    Passenger(PassengerInfo PassengerObj)
    {
        this->PassengerObj = PassengerObj;
        next = NULL;
    }
};

class PassengerList
{
private:
    Passenger *HEAD;
    Passenger *TAIL;

public:
    PassengerList()
    {
        setHead(NULL);
        setTail(NULL);
    }
    bool isEmpty()
    {
        return HEAD == NULL;
    }
    void setHead(Passenger *head)
    {
        this->HEAD = head;
    }
    Passenger *getHead()
    {
        return this->HEAD;
    }
    void setTail(Passenger *tail)
    {
        TAIL = tail;
    }
    Passenger *getTail()
    {
        return this->TAIL;
    }
    void addOnHead(PassengerInfo PassengerObj)
    {
        Passenger *newNode = new Passenger(PassengerObj);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            newNode->next = getHead();
            setHead(newNode);
        }
    }
    void addOnTail(PassengerInfo PassengerObj)
    {
        Passenger *newNode = new Passenger(PassengerObj);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            getTail()->next = newNode;
            newNode->next = NULL;
            setTail(newNode);
        }
    }
    Passenger removeFromHead()
    {
        if (isEmpty())
        {
            cout << "Nothing to Remove!" << endl;
            return Passenger();
        }
        else
        {
            Passenger removedHead(getHead()->PassengerObj);
            Passenger *nextHead = getHead()->next;
            delete getHead();
            setHead(nextHead);
            return removedHead;
        }
    }
    Passenger removeFromTail()
    {
        if (isEmpty())
        {
            cout << "Nothing to remove" << endl;
            return Passenger();
        }
        if (getHead() == getTail())
        {
            Passenger removedPassenger(getHead()->PassengerObj);
            delete getHead();
            setHead(NULL);
            setTail(NULL);
            return removedPassenger;
        }
        else
        {
            Passenger removedTail(getTail()->PassengerObj);
            Passenger *tempNode = getHead();
            while (tempNode != NULL)
            {
                if (tempNode->next == getTail())
                {
                    delete getTail();
                    setTail(tempNode);
                    tempNode->next = NULL;
                    return removedTail;
                }
                tempNode = tempNode->next;
            }
        }
    }
    Passenger *searchPassenger(int id)
    {
        Passenger *tempNode = getHead();

        while (tempNode != NULL)
        {
            if (tempNode->PassengerObj.getId() == id)
            {
                Passenger *foundPassenger = new Passenger(tempNode->PassengerObj);
                return foundPassenger;
            }
            tempNode = tempNode->next;
        }
        Passenger *foundPassenger = new Passenger();
        return foundPassenger;
    }
    Passenger removePassengerBefore(int id)
    {
        // Check at least there are 3 nodes
        if (isEmpty() || getHead()->next == NULL || getHead()->PassengerObj.getId() == id)
        {
            cout << "Can't be removed!" << endl;
            return Passenger();
        }
        else if (getHead()->next->PassengerObj.getId() == id)
        {
            Passenger removedNode(getHead()->PassengerObj);
            removedNode.next = getHead()->next;
            delete getHead();
            setHead(removedNode.next);
            return removedNode;
        }

        // needs at least 3 nodes to check
        else
        {
            Passenger *tempNode = getHead();
            while (tempNode != NULL)
            {
                if (tempNode->next == getTail())
                {
                    return Passenger();
                }
                if (tempNode->next->next->PassengerObj.getId() == id)
                {
                    Passenger *removedNode = tempNode->next;
                    tempNode->next = removedNode->next;
                    Passenger removedPassenger(removedNode->PassengerObj);
                    delete removedNode;
                    return removedPassenger;
                }
                tempNode = tempNode->next;
            }
            return Passenger();
        }
    }
    void printPassengers()
    {
        Passenger *tempNode = getHead();
        cout << "\n================================Passengers List================================" << endl;
        if (tempNode == NULL)
        {
            cout << "Nothing to show !!" << endl;
        }
        while (tempNode != NULL)
        {
            tempNode->PassengerObj.displayPassengerInfo();
            tempNode = tempNode->next;
        }
    }
};

int main()
{
    PassengerList list;

    PassengerInfo passenger1(12345, 1, "Faisal Butt");
    list.addOnHead(passenger1);

    PassengerInfo passenger2(7891, 2, "Ali Ahmed");
    list.addOnTail(passenger2);

    list.removeFromHead();

    Passenger removedPassenger = list.removeFromTail();
    removedPassenger.PassengerObj.displayPassengerInfo();

    Passenger *searchPassenger = list.searchPassenger(4);
    searchPassenger->PassengerObj.displayPassengerInfo();
}