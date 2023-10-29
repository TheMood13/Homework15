#ifndef __Event_H__
#define __Event_H__

#include <TObject.h>

class Event : public TObject {
    public:
        Event(); // default constructor
        Event (Double_t px, Double_t py, Double_t pz); // some other constructor
        virtual ~Event(); // destructor

    private:
        // some private members
        Double_t px;
        Double_t py;
        Double_t pz;

        Double_t Magnitude();

    ClassDef(Event, 1); // Class
};

#endif /* Event_H */