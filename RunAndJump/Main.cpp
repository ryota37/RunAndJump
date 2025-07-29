# include <Siv3D.hpp> // Siv3D v0.6.15

void Main()
{

	Rect background{ 0,-200,7200,800 };
	Circle player{ Scene::Center().x, 550, 30};

	while (System::Update())
	{
		background.draw(Arg::left = Palette::Black, Arg::right = Palette::White);
		player.draw(Palette::Red);

		background.x -= 10;

		// Debug
		if (KeyLeft.pressed())
		{
			background.x += 10;
		}
		if (KeyRight.pressed())
		{
			background.x -= 10;
		}



	}
}
