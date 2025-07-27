# include <Siv3D.hpp> // Siv3D v0.6.15

void Main()
{

	Rect background{ 0,-200,2400,800 };

	while (System::Update())
	{
		background.draw(Arg::left = Palette::Black, Arg::right = Palette::White);


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
