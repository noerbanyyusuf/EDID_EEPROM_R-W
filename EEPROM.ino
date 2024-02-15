void writeEEPROM(int address, byte val, int i2c_address)
{
	Wire.beginTransmission(i2c_address); 
	//uncomment for memory address as two 8-bit bytes
	//Wire.write((int)(address >> 8));   // MSB
	Wire.write((int)(address)); // LSB
	Wire.write(val);
	Wire.endTransmission();
	delay(5);
}
 
byte readEEPROM(int address, int i2c_address)
{
	byte rcvData;
	Wire.beginTransmission(i2c_address);
	//uncomment for memory address as two 8-bit bytes
	//Wire.write((byte)(address >> 8));   // MSB
	Wire.write((byte)(address)); // LSB
	Wire.endTransmission();
	Wire.requestFrom(i2c_address, 1);
	if(Wire.available()) rcvData =  Wire.read();
	return rcvData;
}
