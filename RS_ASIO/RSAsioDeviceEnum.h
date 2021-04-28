#pragma once

#include "RSBaseDeviceEnum.h"
#include "RSAsioDevice.h"

struct RSAsioOutputConfig
{
	std::string asioDriverName;
	unsigned baseChannel = 0;
	std::optional<unsigned> altBaseChannel;
	unsigned numChannels = 2;
	bool enableSoftwareEndpointVolumeControl = true;
	bool enableSoftwareMasterVolumeControl = true;
	int softwareMasterVolumePercent = 100;
};

struct RSAsioInputConfig
{
	std::string asioDriverName;
	unsigned useChannel = 0;
	bool enableSoftwareEndpointVolumeControl = true;
	bool enableSoftwareMasterVolumeControl = true;
	int softwareMasterVolumePercent = 100;
	bool microphone = false;
};

struct RSAsioConfig
{
	RSAsioOutputConfig output;
	std::array<RSAsioInputConfig, 3> inputs;
	RSAsioDevice::BufferSizeMode bufferMode = RSAsioDevice::BufferSizeMode_Driver;
	unsigned customBufferSize = 128;
};

struct RSConfig
{
	bool enableWasapiOutputs = false;
	bool enableWasapiInputs = false;
	bool enableAsio = false;
	RSAsioConfig asioConfig;
};

class RSAsioDeviceEnum : public RSBaseDeviceEnum
{
public:
	void SetConfig(const RSAsioConfig& config);

protected:
	virtual void UpdateAvailableDevices() override;

	RSAsioConfig m_Config;
};
