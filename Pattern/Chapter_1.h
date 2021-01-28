#pragma once
#include <iostream>

class Uint {
public:
	void move(int x, int y) {
		printf("move(%d,%d)\n", x, y);
	}
};

class GameActor {
public:
	void jump() {
		std::cout << "Actor Jump\n" << std::endl;
	}
	void move() {
		std::cout << "Actor Move\n" << std::endl;
	}
	
};

class Command {
public:
	~Command() = default;
	virtual void execute(GameActor*) = 0;
};

class JumpCommand : public Command {
public:
	~JumpCommand() = default;
	void execute(GameActor* act) final{
		act->jump();
	}
};

class MoveCommand : public Command {
public:
	~MoveCommand() = default;
	void execute(GameActor* act) final {
		act->move();
	}
};

class InPutHandle {
public:
	InPutHandle(Command* but_a, Command* but_s) : butten_A(but_a), butten_S(but_s){}
	~InPutHandle() = default;

	std::unique_ptr<Command> operator()(const char button){
		std::unique_ptr<Command> reCommand(nullptr);
		switch (button)
		{
		case 'a':
		case 'A':
			reCommand = std::move(butten_A);
			break;
		case 's':
		case 'S':
			reCommand = std::move(butten_S);
			break;
		default:
			break;
		}

		return std::move(reCommand);
	}

private:
	std::unique_ptr<Command> butten_A;
	std::unique_ptr<Command> butten_S;
};

void Main_Comand() {
	auto actor = std::make_unique<GameActor>();
	auto handle = std::make_unique<InPutHandle>(new JumpCommand, new MoveCommand);
	auto com = handle.get();
	std::unique_ptr<Command> button;

	while (true) {
		button = (*com)(getchar());
		if (button)
		{
			button->execute(actor.get());
			printf("%c", getchar());
		}
		else
		{
			return;
		}
	}
}

/*
class MoveCommand : public Command {
public:
	MoveCommand(Uint* ut, int x, int y) : uint(ut),x(x),y(y),befor_x(x),befor_y(y){

	}
	~MoveCommand() = default;
	void execute() final {
		uint->move(x, y);
	}
	void undo() {

	}
private:
	Uint* uint;

	int x, y;
	int befor_x, befor_y;
};

*/
