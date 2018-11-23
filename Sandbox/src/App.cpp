#include <gilded.h>

class App : public gilded::Application
{
public:
	App() {}
	~App() {}
};

gilded::Application *gilded::CreateApplication()
{
	return new App();
}