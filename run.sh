#
#    First, make sure you are in the Analyzer directory
#    then, run "./run.sh <input_file> <output_file>"
#

g++ src/Main.cpp src/Reader.cpp src/EthernetPacket.cpp src/EcpriPacket.cpp  src/Writer.cpp src/PacketFactory.cpp -o Main.exe
./Main.exe $1 $2