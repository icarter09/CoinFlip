/** 
  Purpose of this program is to showcase the "Law of Large Numbers" through a 
  simulated coin flip. This will show the number of heads and tails averaging off
  to where the proportion of heads and tails is close to 50%.

  Law of Large Numbers shows that after many many trials, the frequency of a given
  outcome gets closer to the true probability of the given outcome.
**/

#define ANALOG_PIN 0
#define HEADS_LED 2
#define TAILS_LED 4

int totalHeadsCount = 0;
int totalTailsCount = 0;
int numberOfFlips = 0;

void setup() {
 pinMode(2, OUTPUT);
 pinMode(4, OUTPUT); 
  
 randomSeed(analogRead(ANALOG_PIN));
 Serial.begin(9600); 
}

void getAverage(int count, int flips) {
    float average = (float)count / (float)flips;  
    Serial.println(average, 6);
    Serial.println("...and this should be getting closer to 0.5");
}

void printFlipCount(int flips) {
    Serial.print("Count after ");
    Serial.print(flips);
    Serial.println(" flips");  
}

void printHeadStats(int flips) {
    Serial.print("Total Heads = ");
    Serial.println(totalHeadsCount);
    Serial.print("..and the average for heads is now at ");
    getAverage(totalHeadsCount, flips);
}

void printTailStats(int flips) {   
    Serial.print("Total Tails = ");
    Serial.println(totalTailsCount);
    Serial.print("..and the average for tails is now at ");
    getAverage(totalTailsCount, flips);
}

void loop() { 
  
 int coinFlip = random(0, 2);
 
 if ( coinFlip == 0) {
   totalHeadsCount++;  
   digitalWrite(2, HIGH);
   delay(250);
   digitalWrite(2, LOW);
 } else {
   totalTailsCount++; 
   digitalWrite(4, HIGH);
   delay(250);
   digitalWrite(4, LOW);
 }
 
 numberOfFlips++;
 
 //display stats after every 10th flip
 if (numberOfFlips % 10 == 0) {
    Serial.println();
    printFlipCount(numberOfFlips);
    printHeadStats(numberOfFlips);
    printTailStats(numberOfFlips);    
 }

}

