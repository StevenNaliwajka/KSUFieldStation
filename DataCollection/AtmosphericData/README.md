CR5 scripts run on the CR5000 Datalogger.
"KSU_Met_20211101.CR5" was what I pulled off the datalogger and started with.

"test_all_values.CR5" prints all data every 10 seconds to serial to verify instrument quality.

The plan is to load data on the datalogger all day then once a day send data
over to the raspberry pi.

Considerations to prevent data loss:
- Data must be logged with a timestamp.
- Data is deleted from the CR5000 after transfered.
- CR5000 waits for 'ready' from the raspberry pi listening.
- checksum on each line to verify transfered correctly.
- handling for daylight savings time?
  - Maybe allow data to be pulled anytime of the day?
  - Have the unit check for a 'ready' come back from serial?
  - See if parallel processing is allowed in the datalogger?
