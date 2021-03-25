# Cpsc3780
Sender sends data to the receiver which sends back an acknowdlegdment message of its own
## Usage
make all compiles both programs
make clean removes all executables
sender HOST PORT sends a pre-written message to the receiver
sender -f [DATAFILE] HOST PORT sends the datafile to the receiver
receiver PORT gets message from sender and returns a pre-written message
receiver -f [DATAFILE] PORT gets message from sender and returns a pre-written message
for best results run sender first then receiver
make testSH compiles tests
testSH runs the tests