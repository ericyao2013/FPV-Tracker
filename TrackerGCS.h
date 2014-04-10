#ifndef TRACKERGCS_H
#define TRACKERGCS_H

#include <LiquidCrystal.h>
#include <Servo.h>
#include <pins_arduino.h>

#define numberOfRSSISamples 10

#define minTrackingDistance 5					// Minimum distance in meters before tracking will start
#define invalidPositionCoordinate 0x7FFFFFFF
#define invalidAltitude 65535

#define verticalServoPin 10
#define horizontalServoPin 11
#define verticalServo 0
#define horizontalServo 1

#define GPSTrackingMode 0
#define RSSITrackingMode 1

#define AeroQuadProtocol 0
#define MikrokopterProtocol 1

#define battAREFValue         4.35					// V
#define battResistorHigh       10.1  				// kOhm
#define battResistorLow        1.48					// kOhm
const int battMonitorPin = A2;

// Telemetry variables
extern float			uavLatitude;                // latitude
extern float			uavLongitude;               // longitude
extern unsigned char    uavSatellitesVisible;		// number of satelites
extern int16_t			uavAltitude;                // altitude (dm)

// Home positioning data
extern float homeLongitude;
extern float homeLatitude;
extern float uavDistanceToHome;
extern unsigned char homeBearing;

// Status indicators
extern bool uavHasGPSFix;
extern bool isTelemetryOk;
extern long lastPacketReceived;

extern LiquidCrystal lcd;

// Tracking variables
extern unsigned char trackingBearing;
extern unsigned char trackingElevation;

const unsigned char verticalMin = 20;
const unsigned char verticalMid = 70;
const unsigned char verticalMax = 120;
const unsigned char horizontalMin = 0;
const unsigned char horizontalMid = 90;
const unsigned char horizontalMax = 180;
const int rssi1 = A0;
const int rssi2 = A1;

extern unsigned char rssiTrack;
extern unsigned char rssiFix;
extern unsigned char rssiTrackOld;
extern unsigned char i;
extern unsigned char y;

extern unsigned char horizontalDirection;
extern unsigned char verticalDirection;

extern Servo VerticalServo;
extern Servo HorizontalServo;

extern unsigned char protocolType;

extern void applyServoCommand(int servo, int value);

#endif
