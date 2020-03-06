#include "main.h"

/*

Please make sure that the active solution platform is set to x86 and the platform is set to Win32.
Otherwise, the game might not be able to compile.


If you would like to run the game in Debug configuration, please make sure the Debug folder (which is in the same folder as the .sln file) contains the following files:
openal32.dll
sfml-audio-d-2.dll
sfml-graphics-d-2.dll
sfml-network-d-2.dll
sfml-system-d-2.dll
sfml-window-d-2.dll
If the folder does not contain these files, you can find a copy of these files in: /Stranded/sfml/bin/Debug


If you would like to run the game in Release configuration, please make sure the Release folder (which is in the same folder as the .sln file) contains the following files:
openal32.dll
sfml-audio-2.dll
sfml-graphics-2.dll
sfml-network-2.dll
sfml-system-2.dll
sfml-window-2.dll
If the folder does not contain these files, you can find a copy of these files in: /Stranded/sfml/bin/Release



Tutorials used:

Basic SFML YouTube playlist 1:
(used to get started with SFML + Animation class + Player class: Update function + Skeleton class: Update function)
https://www.youtube.com/playlist?list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY_SLRW9

Basic SFML YouTube playlist:
(used to get started with SFML + box collision (Character class: CheckCollision and GetCorners function)
+ circle collison (Character class: CheckCollision function))
https://www.youtube.com/playlist?list=PLHJE4y54mpC5j_x90UkuoMZOdmmL9-_rg

Buttons YouTube tutorial: (used to create the Button class) 
https://www.youtube.com/watch?v=KpRbBtlbMfg
https://www.youtube.com/watch?v=xtBNgDncRnU

Changing cursor: (used in main.cpp line 435 - 440)
https://github.com/SFML/SFML/wiki/Tutorial:-Change-Cursor

Converting an int to a string: (used in the Text class to convert the 'score', 'highscore' and 'current wave' ints to strings)
https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c

Dynamically declaring array of object with constructor: (used in main.cpp line 203-213 to create an array of Skeletons)
https://stackoverflow.com/questions/8462895/how-to-dynamically-declare-an-array-of-objects-with-a-constructor-in-c

Setting application icon: (used in main.cpp line 142 - 145)
https://en.sfml-dev.org/forums/index.php?topic=1398.0



Art used:

Crosshair (Images/cursor.png):
https://www.kenney.nl/assets/crosshair-pack

Player (Images/hero.png):
https://opengameart.org/content/2d-hero

Skeleton (Images/skeleton.png):
https://opengameart.org/content/skull-monster-sprite-sheet

Victory prize cup (Images/victoryImage.png):
https://www.pngfuel.com/free-png/aacfk

Clouds (Images/cloud1.png , Images/cloud2.png, Images/cloud3.png):
https://opengameart.org/content/2d-clouds-pack

Water (Images/water.png):
https://bayat.itch.io/platform-game-assets

Tree (Images/Tree.png):
https://2dartforgames.wordpress.com/creative-commons-2d-game-art-assets/



Sounds used:

Main music (Audio/sb_snowfall.ogg):
https://www.audiolibrary.com.co/scott-buckley/snowfall

Shooting sound (Audio/shootSound.wav):
https://freesound.org/people/jalastram/sounds/362458/

Skeleton death sound (Audio/deathSound.wav):
https://freesound.org/people/GameAudio/sounds/220203/

Victory sound (Audio/victorySound.wav):
https://freesound.org/people/Leszek_Szary/sounds/133284/

Game over sound (Audio/gameOver.wav):
https://freesound.org/people/Leszek_Szary/sounds/133283/

Button click sound:
https://freesound.org/people/NenadSimic/sounds/171697/


*/

int main() {


	//Creating a string for each image and sound used (credits)
	std::string crosshairCredits = "Crosshair: \nhttps://www.kenney.nl/assets/crosshair-pack \n'Crosshair Pack' by Kenney, licensed under CC0 1.0 Universal \nhttps://creativecommons.org/publicdomain/zero/1.0/\n\n";
	std::string playerCredits = " Player: \nhttps://opengameart.org/content/2d-hero \n'2D hero' by tokka, licensed under CC BY 3.0 \nhttps://creativecommons.org/licenses/by/3.0/\n\n";
	std::string skeletonCredits = "Skeleton: \nhttps://opengameart.org/content/skull-monster-sprite-sheet \n'Skull Monster Sprite Sheet' by dogchicken, licensed under CC BY 3.0 \nhttps://creativecommons.org/licenses/by/3.0/\n\n";
	std::string prizeCupCredits = " Victory prize cup: \nhttps://www.pngfuel.com/free-png/aacfk\n\n";
	std::string cloudCredits = "Clouds: \nhttps://opengameart.org/content/2d-clouds-pack \n'2D Clouds Pack' by hassekf, licensed under CC BY 3.0 \nhttps://creativecommons.org/licenses/by/3.0/\n\n";
	std::string waterCredits = "Water: \nhttps ://bayat.itch.io/platform-game-assets \n'Platform Game Assets' by Bayat Games, licensed under CC BY 4.0 \nhttps://creativecommons.org/licenses/by/4.0/\n\n";
	std::string treeCredits = "Tree:\nhttps://2dartforgames.wordpress.com/creative-commons-2d-game-art-assets/\n'Palm Tree' by mr0.0nerd\n\n";
	std::string musicCredits = "Main music:\nhttps://www.audiolibrary.com.co/scott-buckley/snowfall\nSnowfall by Scott Buckley https://soundcloud.com/scottbuckley \nCreative Commons — Attribution 4.0 International — CC BY 4.0\nhttps://creativecommons.org/licenses/by/4.0/\nMusic promoted by Audio Library https://youtu.be/jIsaq_7RqjY \n\n";
	std::string shootingSoundCredits = "Shooting sound:\nhttps://freesound.org/people/jalastram/sounds/362458/\n'Shooting_Sounds_008' by jalastram, licensed under CC BY 3.0\nhttps://creativecommons.org/licenses/by/3.0/\n\n";
	std::string skeletonSoundCredits = "Skeleton death sound:\nhttps://freesound.org/people/GameAudio/sounds/220203/\n'Casual Death Loose' by GameAudio, licensed under CC0 1.0 Universal\nhttps://creativecommons.org/publicdomain/zero/1.0/\n\n";
	std::string victorySoundCredits = "Victory sound:\nhttps://freesound.org/people/Leszek_Szary/sounds/133284/\n'level completed' by Leszek_Szary, licensed under CC0 1.0 Universal\nhttps://creativecommons.org/publicdomain/zero/1.0/\n\n";
	std::string gameOverSoundCredits = "Game over sound:\nhttps://freesound.org/people/Leszek_Szary/sounds/133283/\n'game over' by Leszek_Szary, licensed under CC0 1.0 Universal\nhttps://creativecommons.org/publicdomain/zero/1.0/\n\n";
	std::string buttonCredits = "Button click sound:\nhttps://freesound.org/people/NenadSimic/sounds/171697/\n'Menu Selection Click' by NenadSimic, licensed under CC0 1.0 Universal\nhttps://creativecommons.org/publicdomain/zero/1.0/\n\n";


	//Seeding the rand() function (will be used to generate random skeleton size, position and speed)
	srand((unsigned int)time(0));


	//Creating a window which will display our game
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Stranded", sf::Style::Close);

	//Creating a view
	sf::View view(sf::Vector2f(0, 0), (sf::Vector2f) window.getSize());

	//Disable key repetition
	window.setKeyRepeatEnabled(false);

	//Setting the default mouse cursor to invisible
	window.setMouseCursorVisible(false);

	//Setting the application icon 
	sf::Image gameIcon;
	gameIcon.loadFromFile("Images/gameOverImage.png");
	window.setIcon(gameIcon.getSize().x, gameIcon.getSize().y, gameIcon.getPixelsPtr());


	//Loading the fonts (fonts acquired from default fonts that come with Windows 10)
	sf::Font ravieFont;
	ravieFont.loadFromFile("Fonts/RAVIE.ttf");
	sf::Font coprgtlFont;
	coprgtlFont.loadFromFile("Fonts/coprgtl.ttf");

	//Loading in a texture , which will be our mouse cursor in the game
	sf::Texture cursorT;
	cursorT.loadFromFile("Images/cursor.png");
	//Creating a sprite for our mouse cursor
	sf::Sprite cursor = NewSprite( //The NewSprite function is defined at the bottom of this file
		cursorT, sf::Color::Black, //Setting the texture and color of the sprite
		sf::Vector2f(float(cursorT.getSize().x / 2), float(cursorT.getSize().y / 2)), //Setting the origin of the sprite to the center of the sprite
		sf::Vector2f(0,0), sf::Vector2f(0.7f, 0.7f)); //Setting the position to (0,0) and the scale to 0.7f on both X and Y axis

	//Creating a water sprite
	sf::Texture waterT;
	waterT.loadFromFile("Images/water.png");
	sf::Sprite water = NewSprite(waterT, sf::Color::White, sf::Vector2f(0, 0),sf::Vector2f(0,0),  sf::Vector2f(0.25f, 0.25f));
	//These floats will be used to make the water move
	float waveMovement = 0.0f, waveSpeed = 25.0f;

	//Creating 2 tree sprites
	sf::Texture treeT;
	treeT.loadFromFile("images/Tree.png");
	sf::Sprite tree = NewSprite(treeT, sf::Color(255, 255, 255, 200), sf::Vector2f(0, 0),sf::Vector2f(300, 275) ,sf::Vector2f(0.5f, 0.5f));
	sf::Sprite tree2 = NewSprite(treeT, sf::Color(255, 255, 255, 200), sf::Vector2f(0,0), sf::Vector2f(235, 340), sf::Vector2f(0.4f, 0.4f));


	//Creating an island
	sf::CircleShape island;
	island.setRadius(1000); //Setting the circle's radius to 1000
	island.setPointCount(50); //Setting the circle's point count to 50
	island.setOrigin(1000, 1000); //Set the origin to the center of the circle
	island.setPosition(500, 1500); //Setting it's position
	island.setFillColor(sf::Color(255, 255, 175)); //Setting it's color, so it looks like an actual island

	//Creating an instance of the Player class
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Images/hero.png"); //Each sprite is 80x94 pixels, total of 8x5 sprites
	Player player(sf::Vector2f(75, 75), sf::Vector2f(200, 500), //Setting the size and position of the player
		playerTexture, 150.0f, 500.0f, //Setting  the texture , moving speed and jump height, respectively
		sf::Vector2i(8, 5), 0.15f, //Setting the amount of images in the sprite sheet (8 x 5 sprites), and setting the switch time between the sprites (0.15s)
		island,
		/*The Character class needs a reference to the island , to make collision between the characters and the island easy. 
		(The Player class is inherited from the Character class) */
		"Audio/gameOver.wav", 60);  //Setting the sound to be played when the Player dies, and setting the volume of that sound (60%)
	//Creating a pointer to the player (needed for the Skeleton class)
	Character* p = &player;

	//Loading in the skeleton texture
	sf::Texture skeletonTexture;
	skeletonTexture.loadFromFile("Images/skeleton.png"); //Each sprite is 64x64 pixels, total of 8x8 sprites
	skeletonTexture.setSmooth(true); //Setting the texture to smooth, so the individual pixels are less remarkable

	//Creating instances of the Skeleton class and storing them in a vector
	const int skeletonAmount = 24; 
	Skeleton** skeletons; //This pointer will point to another pointer. That pointer will point to an array of skeletons, created on the heap
	skeletons = new Skeleton * [skeletonAmount]; //Creating an array of skeletons on the heap
	for (int i = 0; i < skeletonAmount; i++) { //Looping through each element of the array
		//Creating a skeleton for each element of the array
		*(skeletons + i) = new Skeleton(skeletonTexture, //Setting the texture of the skeleton
			sf::Vector2i(8, 8), 0.15f, //Setting the amount of images in the sprite sheet (8x8 sprites) and setting the switch time between the sprites (0.15s)
			p, island, //Passing a pointer to the player, and a reference to the island. This will be used for collision detection
			"Audio/deathSound.wav", 100); //Setting the sound to be played when the Skeleton dies, and setting the volume of that sound (100%)
	}


	//Creating 5 clouds and storing them in an array
	Cloud clouds[5] = {
		Cloud("Images/cloud1.png", sf::Vector2f(-500, 200), 10.0f), //Setting the texture , position and moving speed of the clouds, respectively
		Cloud("Images/cloud2.png", sf::Vector2f(750, 250), 20.0f),
		Cloud("Images/cloud2.png", sf::Vector2f(0, 164), -15.0f),
		Cloud("Images/cloud3.png", sf::Vector2f(500, 125), -10.0f),
		Cloud("Images/cloud3.png", sf::Vector2f(1500, 150), 15.0f),
	};


	//Loading the music
	sf::Music music;
	music.openFromFile("Audio/sb_snowfall.ogg");
	music.setLoop(true); //Make the music loop
	music.setVolume(25); //Turn down the volume to 25 %
	music.setPlayingOffset(sf::seconds(2)); //Skip the first 2 seconds of the song 
	music.play(); //Playing the music

	//Loading the shoot sound and setting the volume to 60%
	sf::SoundBuffer buffer;
	sf::Sound shootSound;
	buffer.loadFromFile("Audio/shootSound.wav");
	shootSound.setBuffer(buffer);
	shootSound.setVolume(60); 
	

	//Creating ints which will store our score, high score, current wave and the highest wave
	int score = 0, highScore = 0, currentWave = 0, maxWave = 12;;

	//This float will be used to display the waveText for a certain amount of time, because it should not be always visible
	float displayTime = 3.0f;

	//Creating a "Score: X", "High Score: X" and "Wave: X" text, respectively

	Text scoreText("Score: ", score, //Setting the text + the variable which it will display (e.g. "Score: 5")
		coprgtlFont, 25, //Setting the font and font size
		sf::Color::Black //Setting the color of the text 
	); 

	Text hscoreText("High Score: ", highScore, coprgtlFont, 25, sf::Color::Black);
	Text waveText("Wave ", currentWave, coprgtlFont, 45, sf::Color::Red,
		1.0f, sf::Color::Black //Creating an outline and setting it's color to black
	);

	//Setting the origin of the wave text to the center of the text
	waveText.SetOrigin(sf::Vector2f(waveText.GetSize().width / 2.0f, waveText.GetSize().height / 2.0f));


	//Creating a main menu
	Menu menu(true); //True means that it will be open by default when starting the game
	//Creating a Start Game button
	menu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(275, 400), //Setting the size and position of the button, respectively
		"Start Game", coprgtlFont, 17, //Setting the text of the button, the font of that text and the size of the text
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255)); 
		//Setting the default color, color when hovering over the button and color when the button is clicked

	//Creating a How To Play button
	menu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(500, 400),
		"How To Play", coprgtlFont, 17,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a Quit Game button
	menu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(725, 400),
		"Quit Game", coprgtlFont, 17,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a Credits button
	menu.CreateButton(sf::Vector2f(125, 80), sf::Vector2f(500, 530),
		"Credits", coprgtlFont, 17,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a text ("Stranded")
	menu.CreateText(sf::Vector2f(float (window.getSize().x / 2), 150), //Center the text to the center of the screen on the X axis, and 150 on the Y axis 
		"Stranded", ravieFont, //Setting the text to be displayed and the font of the text
		sf::Color::Black, 60); //Setting the color and character size of the text


	//Creating difficulty menu
	Menu difficultyMenu(false); //False means it will not be opened by default when starting the game

	//Creating an Easy button
	difficultyMenu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(275, 300),
		"Easy (6 waves)", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a Medium button
	difficultyMenu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(500, 300),
		"Medium (9 waves)", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a Hard button
	difficultyMenu.CreateButton(sf::Vector2f(150, 150), sf::Vector2f(725, 300),
		"Hard (12 waves)", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a Back button
	difficultyMenu.CreateButton(sf::Vector2f(75, 75), sf::Vector2f(50, 50),
		"Back", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));


	//Creating How To Play menu
	Menu howtoplayMenu(false);

	//Creating a Back button
	howtoplayMenu.CreateButton(sf::Vector2f(75, 75), sf::Vector2f(50, 50),
		"Back", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a black rectangle
	howtoplayMenu.CreateRect(sf::Vector2f(850, 500), sf::Vector2f(float (window.getSize().x / 2),float ( window.getSize().y / 2)), sf::Color(0, 0, 0, 150));

	//Creating text ("How To Play")
	howtoplayMenu.CreateText(sf::Vector2f(float(window.getSize().x / 2), 85), "How To Play", coprgtlFont, sf::Color::White, 50);

	//Creating text: Game explanation
	std::string gameExplanation = "You have stranded on an unknown island. \nYour main goal is to survive all incoming enemy waves. \nThe amount of waves depends on the game difficulty you select.\n\nControls: \n[A]: Move to the left \n[D]: Move to the right \n[Space]: Jump \nMouse: Move to aim \nLeft mouse button: Shoot (Shooting cooldown is 0.5 seconds) \n\nGood luck!";
	howtoplayMenu.CreateText(sf::Vector2f(450, 250),
		gameExplanation
		, coprgtlFont, sf::Color::White, 15);


	//Creating Credits menu
	Menu creditsMenu(false);

	//Creating a Back button
	creditsMenu.CreateButton(sf::Vector2f(75, 75), sf::Vector2f(50, 50),
		"Back", coprgtlFont, 15,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a black rectangle
	creditsMenu.CreateRect(sf::Vector2f(900, 500), sf::Vector2f(float(window.getSize().x / 2), float( window.getSize().y / 2)), sf::Color(0,0,0,150));

	//Creating text "Credits"
	creditsMenu.CreateText(sf::Vector2f(float (window.getSize().x / 2), 85), "Credits", coprgtlFont, sf::Color::White, 50);

	//Creating text: credits (column 1)
	creditsMenu.CreateText(sf::Vector2f(275, 325),
		treeCredits + musicCredits + shootingSoundCredits + skeletonCredits + victorySoundCredits + gameOverSoundCredits
		, coprgtlFont, sf::Color::White, 10);

	//Creating text: credits (column 2)
	creditsMenu.CreateText(sf::Vector2f(725, 335), 
		crosshairCredits + playerCredits + skeletonCredits + prizeCupCredits + waterCredits + cloudCredits + buttonCredits
		, coprgtlFont, sf::Color::White, 10);


	//Creating a game over menu
	Menu gameOverMenu(false);

	//Creating a Main Menu button
	gameOverMenu.CreateButton(sf::Vector2f(150, 75), sf::Vector2f(500, 475),
		"Main Menu", coprgtlFont, 25,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a text ("Game Over!")
	gameOverMenu.CreateText(sf::Vector2f(float(window.getSize().x / 2), 100), "Game Over!", ravieFont, sf::Color::Black, 80);

	//Loading in a texture and creating a sprite in the game over menu
	sf::Texture gameOverImage;
	gameOverImage.loadFromFile("Images/gameOverImage.png");
	gameOverMenu.CreateSprite(gameOverImage, sf::Vector2f(float (window.getSize().x / 2), float (window.getSize().y /2 + 25)), sf::Color::White, sf::Vector2f(5, 5));


	//Creating a victory menu
	Menu victoryMenu(false);

	//Creating a Main Menu button
	victoryMenu.CreateButton(sf::Vector2f(150, 75), sf::Vector2f(500, 475),
		"Main Menu", coprgtlFont, 25,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(25, 25, 25, 255));

	//Creating a text ("Victory!")
	victoryMenu.CreateText(sf::Vector2f(float(window.getSize().x / 2), 100), "Victory!", ravieFont, sf::Color::Black, 80);

	//Loading in a texture and creating a sprite in the game over menu
	sf::Texture victoryImage;
	victoryImage.loadFromFile("Images/victoryImage.png");
	victoryMenu.CreateSprite(victoryImage, sf::Vector2f(float(window.getSize().x / 2), float(window.getSize().y / 2 + 25)), sf::Color::White, sf::Vector2f(0.2f,0.2f));

	//Loading a Sound which will play when opening the victory menu
	sf::SoundBuffer victorySound;
	victorySound.loadFromFile("Audio/victorySound.wav");
	victoryMenu.CreateSound(victorySound);
	


	//Used to add a shooting cooldown
	float shootCooldown = 0.5f;

	//Used to calculate deltaTime each frame
	sf::Clock clock;
	float deltaTime;


	//Main game loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			//Stopping the music and closing the window if the player hits the Close button 
			switch (event.type) {
			case sf::Event::Closed:
				music.stop();
				CloseGame(skeletonAmount, skeletons, window);
				break;
			//Stopping the music and closing the window if the player presses the Escape button 
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape) {
					music.stop();
					CloseGame(skeletonAmount, skeletons, window);
				}
				break;
			}
		}

		//Check if the window is still open, and stop the loop if it is not opened anymore
		if (!window.isOpen())
			break;

		//Getting the position of the mouse, relative to the window
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		//Taking the view into account 
		mousePos.x += view.getCenter().x - (window.getSize().x / 2);
		//Set the position of the 'custom' cursor to the position of the mouse
		cursor.setPosition(mousePos);

		//Calculating deltaTime in seconds
		deltaTime = clock.restart().asSeconds();


		//Code executed when we are in the main menu
		if (menu.IsInMenu()) {

			//Clearing the screen
			window.clear(sf::Color(0, 200, 255));

			//Setting the cursor color to black
			cursor.setColor(sf::Color::Black);

			//Play the music, if it was not playing already
			if (music.getStatus() != sf::Music::Playing)
				music.play();

			//Setting the view
			view.setCenter(float (window.getSize().x / 2),float (window.getSize().y / 2));		
			window.setView(view);

			//Updating the clouds
			for (Cloud& cloud : clouds)
				cloud.Update(deltaTime);

			//Updating the menu
			menu.update(mousePos, deltaTime);

			//Check if a button of the menu is pressed
			if (menu.IsButtonPressed()) {
				//Getting the text of the button that is pressed
				std::string buttonText = menu.GetPressedButton();

				//If it was the "Start Game" button: Close the menu, reset the player position, and open the difficulty menu
				if (buttonText == "Start Game") {
					menu.InMenu(false);
					player.SetPosition(sf::Vector2f(200, 500));
					difficultyMenu.InMenu(true);
				}
				//If the "How To Play" button was pressed: close the menu, and open the how to play menu
				else if (buttonText == "How To Play") {
					menu.InMenu(false);
					howtoplayMenu.InMenu(true);
				}
				//If the "Credits" button was pressed: close the main, and open the credits menu
				else if (buttonText == "Credits") {
					menu.InMenu(false);
					creditsMenu.InMenu(true);
				}
				//If the "Quit Game" button was pressed: stop the music and close the game
				else if (buttonText == "Quit Game") {
					music.stop();
					CloseGame(skeletonAmount, skeletons, window);
				}

			}

			//Drawing everything to the screen (clouds, menu and cursor)
			for (Cloud& cloud : clouds)
				cloud.Draw(window);
			menu.render(window);
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}

		//Code executed when we are in the difficulty selection menu
		else if (difficultyMenu.IsInMenu()) {

			//Clearing the screen
			window.clear(sf::Color(0, 200, 255));

			//Updating the clouds
			for (Cloud& cloud : clouds)
				cloud.Update(deltaTime);

			//Updating the menu
			difficultyMenu.update(mousePos, deltaTime);

			//Check if a button is pressed
			if (difficultyMenu.IsButtonPressed()) {
				//Getting the text of the button that was pressed
				std::string buttonText = difficultyMenu.GetPressedButton();

				//If the player clicked the Easy button: Close the difficulty menu and set the max wave to 6
				if (buttonText == "Easy (6 waves)") {
					maxWave = 6;
					difficultyMenu.InMenu(false);
				}
				//If the player clicked the Mediun button: Close the difficulty menu and set the max wave to 9
				else if (buttonText == "Medium (9 waves)") {
					maxWave = 9;
					difficultyMenu.InMenu(false);
				}
				//If the player clicked the Hard button: Close the difficulty menu and set the max wave to 12
				else if (buttonText == "Hard (12 waves)") {
					maxWave = 12;
					difficultyMenu.InMenu(false);
				}
				//If it was the "Back" button: close the difficulty selection menu and open the main menu
				if (buttonText == "Back") {
					difficultyMenu.InMenu(false);
					menu.InMenu(true);
				}
			}

			//Drawing everything to the screen (clouds, difficulty menu and cursor)
			for (Cloud& cloud : clouds)
				cloud.Draw(window);
			difficultyMenu.render(window);
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}

		//Code executed when we are in the How To Play menu
		else if (howtoplayMenu.IsInMenu()) {

			//Clearing the screen
			window.clear(sf::Color(0, 200, 255));

			//Updating the clouds
			for (Cloud& cloud : clouds)
				cloud.Update(deltaTime);

			//Updating the menu
			howtoplayMenu.update(mousePos, deltaTime);

			//Check if a button of the menu is pressed
			if (howtoplayMenu.IsButtonPressed()) {
				//Getting the text of the button that was pressed
				std::string buttonText = howtoplayMenu.GetPressedButton();

				//If it was the "Back" button: close the How To Play menu and open the main menu
				if (buttonText == "Back") {
					howtoplayMenu.InMenu(false);
					menu.InMenu(true);
				}
			}


			//Drawing everything to the screen (clouds, How To Play menu and cursor)
			for (Cloud& cloud : clouds)
				cloud.Draw(window);
			howtoplayMenu.render(window);
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}

		//Code executed when we are in the credits menu
		else if (creditsMenu.IsInMenu()) {

			//Clearing the screen
			window.clear(sf::Color(0, 200, 255));

			//Updating the clouds
			for (Cloud& cloud : clouds)
				cloud.Update(deltaTime);

			//Updating the menu
			creditsMenu.update(mousePos, deltaTime);

			//Check if a button of the menu is pressed
			if (creditsMenu.IsButtonPressed()) {
				//Getting the text of the button that was pressed
				std::string buttonText = creditsMenu.GetPressedButton();

				//If it was the "Back" button: Close the credits menu, and open the main menu
				if (buttonText == "Back") {
					creditsMenu.InMenu(false);
					menu.InMenu(true);
				}
			}


			//Drawing everything to the screen (clouds, credits menu and cursor)
			for (Cloud& cloud : clouds)
				cloud.Draw(window);
			creditsMenu.render(window);
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}

		//Code executed when we are in-game
		else if (!player.IsDead() && score < TotalScoreNeeded(maxWave)) { 

		//If the player pressed left mouse button and the player is able to shoot (shoot cooldown is 0)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootCooldown <= 0.0f) {

				//Set the shoot cooldown to 0,5 seconds
				shootCooldown = 0.5f;
				//Play the shoot sound
				shootSound.play();
				//Get the mouse location
				sf::Vector2f mouseLocation(sf::Mouse::getPosition(window)); 
					//Looping through every skeleton currently in-game
				for (int i = 0; i < currentWave * 2; i++) {
					if (HitDetection(window, mouseLocation, player, skeletons[i])) {
						//If the player hit a skeleton, increase the score
						score++;
						//Break the for loop, so the player can not kill multiple skeletons with one shot
						break;
					}
				}
			}

			//Setting the cursor color to black if the player is able to shoot (cooldown = 0),
			//and setting it to red if the cooldown is bigger than 0
			if (shootCooldown > 0.0f) {
				//Decreasing the shooting cooldown by delta time
				shootCooldown -= deltaTime;
				cursor.setColor(sf::Color::Red);
			}
			else
				cursor.setColor(sf::Color::Black);

			//Increasing the waveMovement value (used to make the waves move)
			waveMovement += deltaTime * waveSpeed;
			//If the movement of the waves is bigger than the actual size of one water sprite, set the wavemovement back
			if (waveMovement > (waterT.getSize().x * water.getScale().x))
				waveMovement -= waterT.getSize().x * water.getScale().x;


			//Updating animations and positions of the player
			player.Update(deltaTime); 

			//Looping through each skeleton currently in-game
			for (int i = 0; i < currentWave * 2; i++) {
				//Checking if the skeleton is not dead
				if (!skeletons[i]->IsDead()) {
					//Check collision between the player and the skeleton
					if (player.CheckCollision(*(skeletons + i))) {
						//If they are colliding, the player dies
						player.Die(true);
					}
				}
				//Updating the skeleton position and animation
				skeletons[i]->Update(deltaTime);
			} 

			//Updating the clouds
			for (Cloud& cloud : clouds)
				cloud.Update(deltaTime);

			//Checking if the player has reached a new high score
			if (score > highScore)
				highScore = score;

			//Checking if the player's score is big enough to go to the next wave
			//Also, checking if we are not in the last wave yet
			if (score >= TotalScoreNeeded(currentWave) && currentWave < maxWave) {

				//Setting the display time to 3 seconds, which will make the "Wave: X" text display for 3 seconds
				displayTime = 3.0f;

				//Increase the current wave
				currentWave++;

				//Looping through each skeleton currently in-game
				for (int i = 0; i < currentWave * 2; i++) {
					//Resetting the stats: assigning new position, new size and new speed to each skeleton
					skeletons[i]->ResetStats();
				}
			}

			//Setting the view 
			view.setCenter(player.GetPosition().x, //Setting the view X center to the position of the player, so the player is always centered on the screen
				float(window.getSize().y / 2)); //Setting the view Y center to half of the size of the screen
			window.setView(view);
	
			//Updating the score, high score and wave text
			scoreText.Update(sf::Vector2f(view.getCenter().x - (window.getSize().x / 2) + 10, 0), //New position
				25); //New character size (most times the same, but we need to change it sometimes)
			hscoreText.Update(sf::Vector2f(view.getCenter().x - (window.getSize().x / 2) + 10, 25), 25);
			waveText.Update(sf::Vector2f(view.getCenter().x, 125), 45);


			//Clearing the window
			window.clear(sf::Color(0, 200, 255));

			//Drawing everything to the screen
			for (Cloud& cloud : clouds)
				cloud.Draw(window);
			window.draw(tree);
			window.draw(tree2);
			//Draw every skeleton currently ingame to the screen
			for (int i = 0; i < currentWave * 2; i++) {
				skeletons[i]->Draw(window);
			}
			//Drawing water between X = -500 and X = 1500
			for (int i = -500; i < 1500; i += int(waterT.getSize().x * water.getScale().x)) {
				//Setting the position of the water, increasing the X position by waveMovement to let the water move
				water.setPosition(i + waveMovement, window.getSize().y - (waterT.getSize().y * water.getScale().x / 2));
				//Draw the water to the screen
				window.draw(water);
			}
			window.draw(island);
			player.Draw(window);
			scoreText.Draw(window);
			hscoreText.Draw(window);
			//If the displaytime is bigger than 0, draw the "Wave: X" text to the screen, it should not always be displayed 
			if (displayTime > 0.0f) {
				waveText.Draw(window);
				//substract deltaTime from the displayTime
				displayTime -= deltaTime;
			}
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}

		//Code executed when we won the game
		else if (score == TotalScoreNeeded(maxWave)) { 

		//Stop the music
		music.stop();

		//Setting the cursor color to black
		cursor.setColor(sf::Color::Black);

		//Clear the window
		window.clear(sf::Color::Green);

		//Setting the view
		view.setCenter(float(window.getSize().x / 2), float(window.getSize().y / 2));
		window.setView(view);

		//If victory menu was not opened already, open the victory menu
		if (!victoryMenu.IsInMenu())
			victoryMenu.InMenu(true);

		//Updating the score text position and character size
		scoreText.Update(sf::Vector2f(view.getCenter().x - (scoreText.GetSize().width / 2.0f), //Centralizing the text on the screen (on the X axis)
			view.getCenter().y - 125), //Setting the Y position 125 above the center of the screen
			40); //Setting the character size to 40

		//Updating the victory menu
		victoryMenu.update(mousePos, deltaTime);

		//Check if a button of the menu was pressed
		if (victoryMenu.IsButtonPressed()) {

			//Get the text of the pressed button
			std::string buttonText = victoryMenu.GetPressedButton();

			//If the text is "Main Menu"
			if (buttonText == "Main Menu") {
				//Resetting the score, currentWave, gameOver bool and 'bringing the player back alive'
				score = 0;
				currentWave = 0;
				player.Die(false);
				//Exit the victory menu and open the main menu
				victoryMenu.InMenu(false);
				menu.InMenu(true);
			}
		}

		//Drawing everything to the screen (victory menu, score text and cursor)
		victoryMenu.render(window);
		scoreText.Draw(window);
		window.draw(cursor);

		//Display everything on the window
		window.display();
		}		

		//Code executed when game over
		else {	
			//Stopping the music
			music.stop();

			//Setting the cursor color to black
			cursor.setColor(sf::Color::Black);

			//Clearing the window
			window.clear(sf::Color::Red);

			//Setting the view
			view.setCenter(float(window.getSize().x / 2), float(window.getSize().y / 2));
			window.setView(view);

			//If the game over menu was not open yet, open the game over menu
			if (!gameOverMenu.IsInMenu())
				gameOverMenu.InMenu(true);

			//Updating the score text
			scoreText.Update(sf::Vector2f(view.getCenter().x - (scoreText.GetSize().width / 2.0f), view.getCenter().y - 125), 40);

			//Updating the game over menu
			gameOverMenu.update(mousePos, deltaTime);

			//Check if a button of the menu is presses
			if (gameOverMenu.IsButtonPressed()) {
				//Getting the text of the button that is pressed
				std::string buttonText = gameOverMenu.GetPressedButton();
				//If the name is "Main Menu"
				if (buttonText == "Main Menu") {
					//Resetting the score, currentwave, gameOver bool and 'bringing the player back alive'
					score = 0;
					currentWave = 0;
					player.Die(false);
					//Closing the game over menu and open the main menu
					gameOverMenu.InMenu(false);
					menu.InMenu(true);
				}
			}

			//Drawing everything to the screen
			gameOverMenu.render(window);
			scoreText.Draw(window);
			window.draw(cursor);

			//Displaying everything on the window
			window.display();
		}	

	}
}

//Calculates the total score needed to go to the next wave
int TotalScoreNeeded(int currentWave) { 
	int totalScore = 0;
	while (currentWave > 0) {
		totalScore += (currentWave * 2);
		currentWave--;
	}
	return totalScore;
}

//A simple way to create a sprite 
sf::Sprite NewSprite(sf::Texture& texture, sf::Color fillColor, sf::Vector2f origin,sf::Vector2f position, sf::Vector2f scale) {
	sf::Sprite sprite (texture);
	sprite.setColor(fillColor);
	sprite.setPosition(position);
	sprite.setScale(scale);
	sprite.setOrigin(origin);

	return sprite;
}

//Detecting if the player clicked on a skeleton 
bool HitDetection(sf::RenderWindow &window, sf::Vector2f mouseLocation, Player &character, Skeleton* skeleton ) {

	//Check if the skeleton is not dead already
	if (!skeleton->IsDead()) {

		//Get the mouse X position, get the skeleton's X position and the skeleton's X size
		float mouseLocationX = mouseLocation.x + character.GetPosition().x - (window.getSize().x / 2);
		float skeletonLocationX = skeleton->GetPosition().x;
		float skeletonSizeX = skeleton->GetSize().x;

		//If the X of the mouse is within the skeletons size
		if (mouseLocationX > skeletonLocationX - (skeletonSizeX / 2) && mouseLocationX < skeletonLocationX + (skeletonSizeX / 2)) {

			//Get the mouse Y position, get the skeleton's Y position and the skeleton's Y size
			float mouseLocationY = mouseLocation.y;
			float skeletonLocationY = skeleton->GetPosition().y;
			float skeletonSizeY = skeleton->GetSize().y;

			//If the Y of the mouse is within the skeletons size
			if (mouseLocationY > skeletonLocationY - (skeletonSizeY / 2) && mouseLocationY < skeletonLocationY + (skeletonSizeY / 2)) {

				//Kill the skeleton
				skeleton->Die(true);
				//Return true, because we hit a skeleotn
				return true;
			}
		}
	}
	//Return false , because we did not hit any skeleton
	return false;
}

//Close the game and deleting everything from the heap
void CloseGame(const int skeletonAmount, Skeleton** &skeletons, sf::RenderWindow &window) {
	for (int i = 0; i < skeletonAmount; i++) {
		delete skeletons[i];
	}
	delete[] skeletons;
	window.close();
}
