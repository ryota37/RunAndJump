# include <Siv3D.hpp> // Siv3D v0.6.15

bool isPlayerOnGround(const Circle& player)
{
	if (player.y + player.r >= 550) return true;
	return false;
}

void gravity(Circle& player)
{
	if (!isPlayerOnGround(player)) player.y += 5;
}

void AutoScroll(Rect& background)
{
	background.x -= 5;
}

void AutoScroll(Array<Rect>& obstacles)
{
	for (auto& obstacle : obstacles)
	{
		obstacle.x -= 5;
	}
}

void PlayerJump(Circle& player, int& jumpFrame)
{
	if (isPlayerOnGround(player))
	{
		if (KeySpace.down() && jumpFrame <= 0) jumpFrame = 30;
	}

	if (jumpFrame > 0)
	{
		player.moveBy(0, -10);
		jumpFrame--;
	}
}

void DrawObstacles(const Array<Rect>& obstacles)
{
	for (const auto& obstacle : obstacles)
	{
		obstacle.draw(Palette::Green);
	}
}

void Main()
{

	Rect background{ 0,-200,7200,800 };
	Circle player{ Scene::Center().x, 550, 30};
	int jumpFrame = 0;
	Array<Rect> obstacles;
	for (int i = 0; i < 5; ++i)
	{
		obstacles << Rect(i * 1000, 450, 30, 150);
	}



	while (System::Update())
	{
		background.draw(Arg::left = Palette::Black, Arg::right = Palette::White);
		player.draw(Palette::Red);
		DrawObstacles(obstacles);

		AutoScroll(background);
		AutoScroll(obstacles);
		gravity(player);
		PlayerJump(player, jumpFrame);

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
