#ifndef WAITINGCTRL_H
#define WAITINGCTRL_H

#include "Patient.h"
#include "genctrl.h"


class WaitingCtrl: public genCTRL
{
public:

    Patient* searchForPatient(int);
    static WaitingCtrl* getInstance();

private:
    static WaitingCtrl* anInstance;
    WaitingCtrl();

    Patient* aPatient;
};

#endif // WAITINGCTRL_H
