#include "eventHandlerTests.h"

TEST(EventHandler, onClose)
{
	MockApplication app;

	Engine::WindowCloseEvent e;

	bool handledBefore = e.handled();

	auto& onCloseFunctionDefault = app.m_handler.getOnCloseCallback();
	onCloseFunctionDefault(e);

	bool handledDefault = e.handled();

	app.setCallback();
	auto& onCloseFunction = app.m_handler.getOnCloseCallback();

	onCloseFunction(e);

	bool handledAfter = e.handled();

	EXPECT_EQ(false, handledDefault);
	EXPECT_EQ(handledBefore, handledDefault);
	EXPECT_NE(handledBefore, handledAfter);
	EXPECT_EQ(handledAfter, true);
	EXPECT_EQ(handledBefore, false);
}
