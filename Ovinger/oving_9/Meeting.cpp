// TDT4102 Øving 9

#include "Meeting.h"


std::ostream& operator<<(std::ostream& os, const Campus& campus) {
    switch (campus) {
        case Campus::trondheim:
            os << "Trondheim";
            break;
        case Campus::aalesund:
            os << "Ålesund";
            break;
        case Campus::gjoevik:
            os << "Gjøvik";
            break;
    }
    return os;
}

void Meeting::addParticipant(std::shared_ptr<Person> participant) {
    participants.push_back(participant);
}

std::vector<std::string> Meeting::getParticipantsList() const{
    std::vector<std::string> participantsNames; 
    for (const auto& participant : participants) {
        participantsNames.emplace_back(participant -> getName());
    }
    return participantsNames;
}

std::ostream& operator<<(std::ostream& os, const Meeting& m) {
    os <<  "Subject: " << m.getSubject() << "\nLocation: " << m.getLocation();
    os << "\nstartTime: " << m.getStartTime() << "\nendTime: " << m.getEndTime();
    os << "\nName of participants: " << "\n";
    for (int i{1}; i < m.getParticipantsList().size(); i++) {
        os << m.getParticipantsList().at(0) << ", " << m.getParticipantsList().at(i);
    } os << std::endl;
    return os;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting& rhs) {
    std::vector<std::shared_ptr<Person>> multipleParticipants;
    bool campusStatement = this -> getLocation() == rhs.getLocation();
    bool dayStatement = this -> getDay() == rhs.getDay();
    bool timeStatement = (rhs.getStartTime() -  1) <= this -> getStartTime() && this -> getStartTime() <= (rhs.getStartTime() +  1) && rhs.getEndTime() - 1 <= this -> getEndTime() && this -> getEndTime() <= rhs.getEndTime() + 1;

    if (campusStatement && dayStatement && timeStatement) {
        std::cout << "true statements" << std::endl;
        for (const auto& dude : rhs.getParticipants()) {
        multipleParticipants.push_back(dude);
        }
    } else {
        std::cout << "false statements" << std::endl;
    }
    return multipleParticipants;
}


