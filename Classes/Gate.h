#pragma once

class Gate : public Amongsus
{
public:

	Gate();
	virtual	~Gate();
	virtual bool init() override;
	void update(std::vector<Amongsus> sussybaka);
	CREATE_FUNC(Gate);

private:
	int max_Entity;

};