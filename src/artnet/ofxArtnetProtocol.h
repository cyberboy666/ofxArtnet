#pragma once
#include "ofMain.h"
#include "ofxNetwork.h"

class ofxArtnetProtocol
{
	public:
		ofxArtnetProtocol();
		~ofxArtnetProtocol();

		void allocateArtnetBuffer(std::vector<unsigned char>& buff, unsigned int size);
		void createProtocolHeader(std::vector<unsigned char>& buff, unsigned char seq = 0);
		void createArtSyncPacket(std::vector<unsigned char>& buff);

	protected:
		ofxUDPManager udp;
		const std::string HEAD = "Art-Net";
		static constexpr int HEADER_LENGTH = 18;
		static constexpr short OP_OUTPUT = 0x5000;
		static constexpr short OP_ARTSYNC = 0x5200;
};
