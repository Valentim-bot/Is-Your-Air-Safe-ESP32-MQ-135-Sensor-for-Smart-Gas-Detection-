
#include <Adafruit_GFX.h> // Include the Adafruit GFX library for graphics functions
#include <Adafruit_SSD1306.h> // Include the Adafruit SSD1306 library for the OLED display

// OLED display configuration
#define SCREEN_WIDTH 128 // Define the OLED display width in pixels
#define SCREEN_HEIGHT 64 // Define the OLED display height in pixels
#define OLED_RESET -1 // Define the reset pin for the OLED display (-1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT); // Create an instance of the display object

const int Gas34 = 34; 
//pins that works with internet
//analogRead( 39 );
//analogRead( 34 );
//analogRead( 35 );
//analogRead( 32 );
//analogRead( 33 );


int data;  
void setup() {
 
  Serial.begin(9600);
  pinMode(Gas34, INPUT);
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Check if the display initializes correctly with I2C address 0x3C
    Serial.println(F("SSD1306 allocation failed")); // Print error message if initialization fails
    while (true); // Stay in an infinite loop if initialization fails
  }
  
  display.clearDisplay(); // Clear the display buffer
  display.setTextSize(3); // Set text size to 2
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setCursor(0, 10); // Set cursor position at (0, 10)
  display.println(F("Initializing...")); // Print "Initializing..." on the display
  display.display(); // Update the display with the above settings
  //delay(2000); // Wait for 2 seconds
}

void loop() {
   data = analogRead(Gas34);
  display.setCursor(15, 45);
  //display.println(data);
  delay(1000);
  Serial.println(data);
  
  if(data > 300){
    //Blynk.email("test@gmail.com", "Alert", "Gas Leakage Detected!");
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(42, 0);
    display.println(F("GAS"));
    display.setCursor(15, 20);
    display.println(F("has been"));
    display.setCursor(15, 45);
    display.println(F("Detected."));
    display.display();
  
  }
  else {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(26, 15);
    display.println(F("No GAS"));
    display.setCursor(15, 45);
    display.println(F("Detected."));
    display.display();

}}

