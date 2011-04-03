#include "waitingctrl.h"
#include "mapwinctrl.h"

WaitingCtrl* WaitingCtrl::anInstance = NULL;

WaitingCtrl::WaitingCtrl(){aPatient = new Patient();}

WaitingCtrl* WaitingCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new WaitingCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return tAddFacCtrlhe instance.
}

Patient* WaitingCtrl::searchForPatient(int health){

    for(int i = 0; i < MapWinCtrl::getInstance()->listOfFacility.size(); i++){

        qDebug() << "Size of complex: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientComplex();
        qDebug() << "Size of Acute: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientAcute();
        qDebug() << "Size of LTC: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientLTC();

        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->isEmpty())){

            for(int j = 0; j < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientComplex(); j++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j);
                    qDebug() << "Health card number inside Waiting Ctrl: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard();
                    return aPatient;
                }
            }
        }
        else if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->isEmpty())){

            for(int k = 0; k < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientAcute(); k++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k);
                    qDebug() << "Health card number inside Waiting Acute: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k)->gethealthCard();
                    return aPatient;
                }
            }
        }
        else if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->isEmpty())){

            for(int l = 0; l < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientLTC(); l++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l);
                    qDebug() << "Health card number inside Waiting LTC: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l)->gethealthCard();
                    return aPatient;
                }
            }

        }

    }

}
