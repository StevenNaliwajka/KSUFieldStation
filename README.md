# KSUFieldStation
(DOCUMENTATION) Parent Repo for any of my work at Kennesaw's field station.

## Nodes: "One-Click" install packages
[KSU-OfficeNode](https://github.com/StevenNaliwajka/KSU-OfficeNode) - One-Click for the PC at the office.  
-Logs TVWS browser info.  
-Transmits all data to endpoint.

[KSU-TowerNode](https://github.com/StevenNaliwajka/KSU-TowerNode) - One-Click for the RaspberryPI at the tower.  
-Collects SDR Data  
-Collects Soil Moisture & Temp Data  
-Collects Atmospheric Data  
-Packages and Sends to OfficeNode

[KSU-AnalysisNode](https://github.com/StevenNaliwajka/KSU-AnalysisNode) - One-Click for personal machines.  
-Package of analyze tools.  
-TBD

## Tools/Repos Inside of Nodes
(private) [Passwords](https://github.com/StevenNaliwajka/KSUFieldStationPasswords) - Private
list of passwords for anything at the station.

[TVWSDataScraper](https://github.com/StevenNaliwajka/TVWSDataScraper) - Selenium based webscraper to automate data 
collection for the 'GWS5000' TV White Space radio unit by 6Harmonics.

[EmailSender](https://github.com/StevenNaliwajka/EmailSender) - A lightweight, configuration-driven email sender 
designed to be invoked by other programs for dispatching error notifications.

[SoilSensingKSUFieldStation](https://github.com/StevenNaliwajka/SoilSensingKSUFieldStation) - Documentation 
for the soil and moisture sensing currently running @ tower.