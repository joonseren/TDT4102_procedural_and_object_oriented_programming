// TDT4102 Øving 9

#pragma once
#include "Person.h"
#include <vector>
enum class Campus {
trondheim, aalesund, gjoevik
};

std::ostream& operator<<(std::ostream& os, const Campus& campus);


class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;

public:
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject,  const std::shared_ptr<Person> leader) :
            day(day), startTime(startTime), endTime(endTime), location(location), subject(subject), leader(leader) {
                participants.push_back(leader);
            }

    int getDay() const {return day;}
    int getStartTime() const {return startTime;}
    int getEndTime() const {return endTime;}
    Campus getLocation() const{return location;}
    std::string getSubject() const {return subject;}
    std::vector<std::shared_ptr<Person>> getParticipants() const{return participants;}
    void addParticipant(std::shared_ptr<Person> participant);
    std::vector<std::string> getParticipantsList() const;
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting& m);
};


std::ostream& operator<<(std::ostream& os, const Meeting& m);
