Ass5:Party.o DemocraticParty.o RepublicanParty.o Politician.o DemocraticPolitician.o DemocraticPoliticianLeader.o DemocraticPoliticianSocial.o RepublicanPolitician.o RepublicanPoliticianLeader.o RepublicanPoliticianSocial.o PoliticalSys.o main.o
	c++ Party.o DemocraticParty.o RepublicanParty.o Politician.o DemocraticPolitician.o DemocraticPoliticianLeader.o DemocraticPoliticianSocial.o RepublicanPolitician.o RepublicanPoliticianLeader.o RepublicanPoliticianSocial.o PoliticalSys.o main.o -o Ass5
DemocraticParty.o:DemocraticParty.cpp DemocraticParty.h Party.h DemocraticPolitician.h Politician.h
	c++ -c DemocraticParty.cpp
DemocraticPolitician.o:DemocraticPolitician.cpp DemocraticPolitician.h Politician.h
	c++ -c DemocraticPolitician.cpp
DemocraticPoliticianLeader.o:DemocraticPoliticianLeader.cpp DemocraticPoliticianLeader.h DemocraticPolitician.h Politician.h
	c++ -c DemocraticPoliticianLeader.cpp
DemocraticPoliticianSocial.o:DemocraticPoliticianSocial.cpp DemocraticPoliticianSocial.h DemocraticPolitician.h Politician.h
	c++ -c DemocraticPoliticianSocial.cpp
main.o:main.cpp PoliticalSys.h Party.h Politician.h
	c++ -c main.cpp
Party.o:Party.cpp Party.h Politician.h
	c++ -c Party.cpp
PoliticalSys.o:PoliticalSys.cpp PoliticalSys.h Party.h Politician.h DemocraticParty.h RepublicanParty.h DemocraticPoliticianSocial.h DemocraticPolitician.h DemocraticPoliticianLeader.h RepublicanPoliticianSocial.h RepublicanPolitician.h RepublicanPoliticianLeader.h
	c++ -c PoliticalSys.cpp
Politician.o:Politician.cpp Politician.h Party.h
	c++ -c Politician.cpp
RepublicanParty.o:RepublicanParty.cpp RepublicanParty.h Party.h RepublicanPolitician.h Politician.h
	c++ -c RepublicanParty.cpp
RepublicanPolitician.o:RepublicanPolitician.cpp RepublicanPolitician.h Politician.h
	c++ -c RepublicanPolitician.cpp
RepublicanPoliticianLeader.o:RepublicanPoliticianLeader.cpp RepublicanPoliticianLeader.h RepublicanPolitician.h Politician.h
	c++ -c RepublicanPoliticianLeader.cpp
RepublicanPoliticianSocial.o:RepublicanPoliticianSocial.cpp RepublicanPoliticianSocial.h RepublicanPolitician.h Politician.h
	c++ -c RepublicanPoliticianSocial.cpp
clean:
	rm -f *.o
