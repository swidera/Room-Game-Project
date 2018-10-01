all: christmasGame

christmasGame: BackyardShed.h BackyardShed.cpp Basement.h Basement.cpp Kitchen.h Kitchen.cpp LivingRoom.h LivingRoom.cpp ParentRoom.h ParentRoom.cpp Space.h Space.cpp YourRoom.h YourRoom.cpp mainSpaceGame.cpp
	g++ BackyardShed.h BackyardShed.cpp Basement.h Basement.cpp Kitchen.h Kitchen.cpp LivingRoom.h LivingRoom.cpp ParentRoom.h ParentRoom.cpp Space.h Space.cpp YourRoom.h YourRoom.cpp mainSpaceGame.cpp -o christmasGame
clean:
	rm christmasGame
