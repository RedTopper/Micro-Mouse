<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="micromouse">
<packages>
<package name="VL6180">
<pad name="VIN" x="1.27" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="GND" x="1.27" y="3.81" drill="1.016" diameter="1.778"/>
<pad name="SCL" x="1.27" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="SDA" x="1.27" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="GPIO" x="1.27" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="XSHUT" x="1.27" y="13.97" drill="1.016" diameter="1.778"/>
<wire x1="0" y1="0" x2="2.54" y2="0" width="0.127" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="15.24" width="0.127" layer="21"/>
<wire x1="2.54" y1="15.24" x2="0" y2="15.24" width="0.127" layer="21"/>
<wire x1="0" y1="15.24" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-5.08" width="0.127" layer="21"/>
<wire x1="2.54" y1="-5.08" x2="5.08" y2="-5.08" width="0.127" layer="21"/>
<wire x1="5.08" y1="-5.08" x2="5.08" y2="6.35" width="0.127" layer="21"/>
<wire x1="5.08" y1="6.35" x2="5.08" y2="8.89" width="0.127" layer="21"/>
<wire x1="5.08" y1="8.89" x2="5.08" y2="20.32" width="0.127" layer="21"/>
<wire x1="5.08" y1="20.32" x2="2.54" y2="20.32" width="0.127" layer="21"/>
<wire x1="2.54" y1="20.32" x2="2.54" y2="15.24" width="0.127" layer="21"/>
<wire x1="5.08" y1="8.89" x2="6.35" y2="8.89" width="0.127" layer="21"/>
<wire x1="6.35" y1="8.89" x2="6.35" y2="6.35" width="0.127" layer="21"/>
<wire x1="6.35" y1="6.35" x2="5.08" y2="6.35" width="0.127" layer="21"/>
<text x="1.778" y="16.002" size="1.27" layer="21" font="vector" align="bottom-right">XS</text>
<text x="1.651" y="-1.905" size="1.27" layer="21" font="vector" align="bottom-right">VCC</text>
<text x="-1.27" y="7.62" size="2.54" layer="25" font="vector" rot="R90" align="bottom-center">&gt;NAME</text>
</package>
<package name="ESP32">
<pad name="21" x="1.27" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="TX/17" x="1.27" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="RX/16" x="1.27" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="MISO/19" x="1.27" y="13.97" drill="1.016" diameter="1.778"/>
<pad name="MOSI/18" x="1.27" y="16.51" drill="1.016" diameter="1.778"/>
<pad name="SCK/5" x="1.27" y="19.05" drill="1.016" diameter="1.778"/>
<pad name="A5/4" x="1.27" y="21.59" drill="1.016" diameter="1.778"/>
<pad name="A4/36" x="1.27" y="24.13" drill="1.016" diameter="1.778"/>
<pad name="A3/39" x="1.27" y="26.67" drill="1.016" diameter="1.778"/>
<pad name="A2/34" x="1.27" y="29.21" drill="1.016" diameter="1.778"/>
<pad name="A1/DAC1" x="1.27" y="31.75" drill="1.016" diameter="1.778"/>
<pad name="A0/DAC2" x="1.27" y="34.29" drill="1.016" diameter="1.778"/>
<pad name="GND" x="1.27" y="36.83" drill="1.016" diameter="1.778"/>
<pad name="NC" x="1.27" y="39.37" drill="1.016" diameter="1.778"/>
<pad name="3V" x="1.27" y="41.91" drill="1.016" diameter="1.778"/>
<pad name="RST" x="1.27" y="44.45" drill="1.016" diameter="1.778"/>
<pad name="SDA/23" x="21.59" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="SCL/22" x="21.59" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="14/A6" x="21.59" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="32/A7" x="21.59" y="13.97" drill="1.016" diameter="1.778"/>
<pad name="15/A8" x="21.59" y="16.51" drill="1.016" diameter="1.778"/>
<pad name="33/A9" x="21.59" y="19.05" drill="1.016" diameter="1.778"/>
<pad name="27/A10" x="21.59" y="21.59" drill="1.016" diameter="1.778"/>
<pad name="12/A11" x="21.59" y="24.13" drill="1.016" diameter="1.778"/>
<pad name="13/A12" x="21.59" y="26.67" drill="1.016" diameter="1.778"/>
<pad name="USB" x="21.59" y="29.21" drill="1.016" diameter="1.778"/>
<pad name="EN" x="21.59" y="31.75" drill="1.016" diameter="1.778"/>
<pad name="BAT" x="21.59" y="34.29" drill="1.016" diameter="1.778"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.127" layer="21"/>
<wire x1="0" y1="5.08" x2="0" y2="45.72" width="0.127" layer="21"/>
<wire x1="0" y1="45.72" x2="0" y2="50.8" width="0.127" layer="21"/>
<wire x1="0" y1="50.8" x2="22.86" y2="50.8" width="0.127" layer="21"/>
<wire x1="22.86" y1="50.8" x2="22.86" y2="35.56" width="0.127" layer="21"/>
<wire x1="22.86" y1="35.56" x2="22.86" y2="5.08" width="0.127" layer="21"/>
<wire x1="22.86" y1="5.08" x2="22.86" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="0" x2="22.86" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="45.72" x2="2.54" y2="45.72" width="0.127" layer="21"/>
<wire x1="2.54" y1="45.72" x2="2.54" y2="5.08" width="0.127" layer="21"/>
<wire x1="2.54" y1="5.08" x2="0" y2="5.08" width="0.127" layer="21"/>
<wire x1="22.86" y1="35.56" x2="20.32" y2="35.56" width="0.127" layer="21"/>
<wire x1="20.32" y1="35.56" x2="20.32" y2="5.08" width="0.127" layer="21"/>
<wire x1="20.32" y1="5.08" x2="22.86" y2="5.08" width="0.127" layer="21"/>
<text x="-0.762" y="45.974" size="1.27" layer="25" font="vector" rot="R90" align="bottom-right">RST</text>
<text x="-0.762" y="7.366" size="1.27" layer="25" font="vector" rot="R90" align="bottom-right">21</text>
<text x="24.638" y="3.302" size="1.27" layer="25" font="vector" rot="R90">SDA/23</text>
<text x="24.638" y="32.766" size="1.27" layer="25" font="vector" rot="R90">BAT</text>
<text x="26.035" y="19.05" size="2.54" layer="25" font="vector" rot="R90">FEATHER</text>
</package>
<package name="12VBOOST">
<pad name="VO" x="1.27" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="GNDO" x="3.81" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="GNDI" x="6.35" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="VI" x="8.89" y="1.27" drill="1.016" diameter="1.778"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.127" layer="21"/>
<wire x1="10.16" y1="0" x2="10.16" y2="2.54" width="0.127" layer="21"/>
<wire x1="10.16" y1="2.54" x2="0" y2="2.54" width="0.127" layer="21"/>
<wire x1="0" y1="2.54" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="11.43" y1="2.54" x2="11.43" y2="3.81" width="0.127" layer="21"/>
<wire x1="11.43" y1="3.81" x2="-10.16" y2="3.81" width="0.127" layer="21"/>
<wire x1="-10.16" y1="3.81" x2="-10.16" y2="2.54" width="0.127" layer="21"/>
<wire x1="-10.16" y1="2.54" x2="11.43" y2="2.54" width="0.127" layer="21"/>
<text x="-0.635" y="-0.508" size="2.54" layer="26" font="vector" rot="MR0">BOOST</text>
<text x="2.159" y="-1.524" size="1.27" layer="26" font="vector" rot="MR0">VO</text>
<text x="9.652" y="-1.524" size="1.27" layer="26" font="vector" rot="MR0">VI</text>
<text x="6.731" y="-1.524" size="1.27" layer="26" font="vector" rot="MR0">GND</text>
</package>
<package name="MOTOR">
<pad name="GND2" x="1.27" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="VMOT" x="1.27" y="3.81" drill="1.016" diameter="1.778"/>
<pad name="B01" x="1.27" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="B02" x="1.27" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="A02" x="1.27" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="A01" x="1.27" y="13.97" drill="1.016" diameter="1.778"/>
<pad name="VCC" x="1.27" y="16.51" drill="1.016" diameter="1.778"/>
<pad name="GND1" x="1.27" y="19.05" drill="1.016" diameter="1.778"/>
<wire x1="0" y1="0" x2="2.54" y2="0" width="0.127" layer="21"/>
<wire x1="2.54" y1="0" x2="12.7" y2="0" width="0.127" layer="21"/>
<wire x1="12.7" y1="0" x2="15.24" y2="0" width="0.127" layer="21"/>
<wire x1="15.24" y1="0" x2="15.24" y2="20.32" width="0.127" layer="21"/>
<wire x1="15.24" y1="20.32" x2="12.7" y2="20.32" width="0.127" layer="21"/>
<wire x1="12.7" y1="20.32" x2="2.54" y2="20.32" width="0.127" layer="21"/>
<wire x1="2.54" y1="20.32" x2="0" y2="20.32" width="0.127" layer="21"/>
<wire x1="0" y1="20.32" x2="0" y2="0" width="0.127" layer="21"/>
<pad name="GND" x="13.97" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="PWMB" x="13.97" y="3.81" drill="1.016" diameter="1.778"/>
<pad name="BIN2" x="13.97" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="BIN1" x="13.97" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="STBY" x="13.97" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="AIN1" x="13.97" y="13.97" drill="1.016" diameter="1.778"/>
<pad name="AIN2" x="13.97" y="16.51" drill="1.016" diameter="1.778"/>
<pad name="PWMA" x="13.97" y="19.05" drill="1.016" diameter="1.778"/>
<wire x1="2.54" y1="20.32" x2="2.54" y2="0" width="0.127" layer="21"/>
<wire x1="12.7" y1="20.32" x2="12.7" y2="0" width="0.127" layer="21"/>
<text x="2.921" y="20.955" size="1.27" layer="25" font="vector" align="bottom-right">GND</text>
<text x="2.794" y="-1.905" size="1.27" layer="25" font="vector" align="bottom-right">GND</text>
<text x="11.938" y="20.955" size="1.27" layer="25" font="vector">PWMA</text>
<text x="12.446" y="-1.778" size="1.27" layer="25" font="vector">GND</text>
<text x="15.748" y="15.113" size="2.54" layer="25" font="vector" rot="R270">MOTOR</text>
</package>
<package name="ENCODE">
<pad name="GND" x="1.27" y="1.27" drill="1.016" diameter="1.778"/>
<pad name="OUTB" x="1.27" y="3.81" drill="1.016" diameter="1.778"/>
<pad name="OUTA" x="1.27" y="6.35" drill="1.016" diameter="1.778"/>
<pad name="VCC" x="1.27" y="8.89" drill="1.016" diameter="1.778"/>
<pad name="M2" x="1.27" y="11.43" drill="1.016" diameter="1.778"/>
<pad name="M1" x="1.27" y="13.97" drill="1.016" diameter="1.778"/>
<wire x1="0" y1="0" x2="2.54" y2="0" width="0.127" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="15.24" width="0.127" layer="21"/>
<wire x1="2.54" y1="15.24" x2="0" y2="15.24" width="0.127" layer="21"/>
<wire x1="0" y1="15.24" x2="0" y2="0" width="0.127" layer="21"/>
<text x="0.254" y="15.875" size="1.27" layer="25" font="vector">M1</text>
<text x="-0.254" y="-1.778" size="1.27" layer="25" font="vector">GND</text>
<text x="-0.635" y="7.62" size="2.54" layer="25" font="vector" rot="R90" align="bottom-center">&gt;NAME</text>
</package>
</packages>
<symbols>
<symbol name="VL6180">
<pin name="XSHUT" x="15.24" y="2.54" length="middle" rot="R180"/>
<pin name="GPIO" x="15.24" y="5.08" length="middle" rot="R180"/>
<pin name="SDA" x="15.24" y="7.62" length="middle" rot="R180"/>
<pin name="SCL" x="15.24" y="10.16" length="middle" rot="R180"/>
<pin name="GND" x="15.24" y="12.7" length="middle" rot="R180"/>
<pin name="VIN" x="15.24" y="15.24" length="middle" rot="R180"/>
<wire x1="10.16" y1="0" x2="10.16" y2="17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="17.78" x2="0" y2="17.78" width="0.254" layer="94"/>
<wire x1="0" y1="17.78" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="ESP32">
<pin name="21" x="-5.08" y="0" length="middle"/>
<pin name="TX/17" x="-5.08" y="2.54" length="middle"/>
<pin name="RX/16" x="-5.08" y="5.08" length="middle"/>
<pin name="MISO/19" x="-5.08" y="7.62" length="middle"/>
<pin name="MOSI/18" x="-5.08" y="10.16" length="middle"/>
<pin name="SCK/5" x="-5.08" y="12.7" length="middle"/>
<pin name="A5/4" x="-5.08" y="15.24" length="middle"/>
<pin name="A4/36" x="-5.08" y="17.78" length="middle"/>
<pin name="A3/39" x="-5.08" y="20.32" length="middle"/>
<pin name="A2/34" x="-5.08" y="22.86" length="middle"/>
<pin name="A1/DAC1" x="-5.08" y="25.4" length="middle"/>
<pin name="A0/DAC2" x="-5.08" y="27.94" length="middle"/>
<pin name="GND" x="-5.08" y="30.48" length="middle"/>
<pin name="NC" x="-5.08" y="33.02" length="middle"/>
<pin name="3V" x="-5.08" y="35.56" length="middle"/>
<pin name="RST" x="-5.08" y="38.1" length="middle"/>
<pin name="SDA/23" x="27.94" y="0" length="middle" rot="R180"/>
<pin name="SCL/22" x="27.94" y="2.54" length="middle" rot="R180"/>
<pin name="14/A6" x="27.94" y="5.08" length="middle" rot="R180"/>
<pin name="32/A7" x="27.94" y="7.62" length="middle" rot="R180"/>
<pin name="15/A8" x="27.94" y="10.16" length="middle" rot="R180"/>
<pin name="33/A9" x="27.94" y="12.7" length="middle" rot="R180"/>
<pin name="27/A10" x="27.94" y="15.24" length="middle" rot="R180"/>
<pin name="12/A11" x="27.94" y="17.78" length="middle" rot="R180"/>
<pin name="13/A12" x="27.94" y="20.32" length="middle" rot="R180"/>
<pin name="USB" x="27.94" y="22.86" length="middle" rot="R180"/>
<pin name="EN" x="27.94" y="25.4" length="middle" rot="R180"/>
<pin name="BAT" x="27.94" y="27.94" length="middle" rot="R180"/>
<wire x1="0" y1="40.64" x2="10.16" y2="40.64" width="0.254" layer="94"/>
<wire x1="10.16" y1="40.64" x2="12.7" y2="40.64" width="0.254" layer="94"/>
<wire x1="12.7" y1="40.64" x2="22.86" y2="40.64" width="0.254" layer="94"/>
<wire x1="22.86" y1="40.64" x2="22.86" y2="38.1" width="0.254" layer="94"/>
<wire x1="22.86" y1="38.1" x2="22.86" y2="33.02" width="0.254" layer="94"/>
<wire x1="22.86" y1="33.02" x2="22.86" y2="-2.54" width="0.254" layer="94"/>
<wire x1="22.86" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="40.64" width="0.254" layer="94"/>
<wire x1="10.16" y1="40.64" x2="10.16" y2="38.1" width="0.254" layer="94"/>
<wire x1="10.16" y1="38.1" x2="12.7" y2="38.1" width="0.254" layer="94"/>
<wire x1="12.7" y1="38.1" x2="12.7" y2="40.64" width="0.254" layer="94"/>
<wire x1="22.86" y1="38.1" x2="17.78" y2="38.1" width="0.254" layer="94"/>
<wire x1="17.78" y1="38.1" x2="17.78" y2="36.83" width="0.254" layer="94"/>
<wire x1="17.78" y1="36.83" x2="17.78" y2="34.544" width="0.254" layer="94"/>
<wire x1="17.78" y1="34.544" x2="17.78" y2="33.02" width="0.254" layer="94"/>
<wire x1="17.78" y1="33.02" x2="22.86" y2="33.02" width="0.254" layer="94"/>
<wire x1="17.78" y1="34.544" x2="20.32" y2="34.544" width="0.254" layer="94"/>
<wire x1="17.78" y1="36.83" x2="20.32" y2="36.83" width="0.254" layer="94"/>
</symbol>
<symbol name="12VBOOST">
<pin name="VO" x="15.24" y="2.54" length="middle" rot="R180"/>
<pin name="GNDO" x="15.24" y="5.08" length="middle" rot="R180"/>
<pin name="GNDI" x="15.24" y="7.62" length="middle" rot="R180"/>
<pin name="VI" x="15.24" y="10.16" length="middle" rot="R180"/>
<wire x1="10.16" y1="0" x2="10.16" y2="12.7" width="0.254" layer="94"/>
<wire x1="10.16" y1="12.7" x2="0" y2="12.7" width="0.254" layer="94"/>
<wire x1="0" y1="12.7" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="MOTOR">
<pin name="GND2" x="0" y="2.54" length="middle"/>
<pin name="VMOT" x="0" y="5.08" length="middle"/>
<pin name="B01" x="0" y="7.62" length="middle"/>
<pin name="B02" x="0" y="10.16" length="middle"/>
<pin name="A02" x="0" y="12.7" length="middle"/>
<pin name="A01" x="0" y="15.24" length="middle"/>
<pin name="VCC" x="0" y="17.78" length="middle"/>
<pin name="GND1" x="0" y="20.32" length="middle"/>
<pin name="PWMA" x="30.48" y="20.32" length="middle" rot="R180"/>
<pin name="AIN2" x="30.48" y="17.78" length="middle" rot="R180"/>
<pin name="AIN1" x="30.48" y="15.24" length="middle" rot="R180"/>
<pin name="STBY" x="30.48" y="12.7" length="middle" rot="R180"/>
<pin name="BIN1" x="30.48" y="10.16" length="middle" rot="R180"/>
<pin name="BIN2" x="30.48" y="7.62" length="middle" rot="R180"/>
<pin name="PWMB" x="30.48" y="5.08" length="middle" rot="R180"/>
<pin name="GND" x="30.48" y="2.54" length="middle" rot="R180"/>
<wire x1="5.08" y1="22.86" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="25.4" y2="0" width="0.254" layer="94"/>
<wire x1="25.4" y1="0" x2="25.4" y2="22.86" width="0.254" layer="94"/>
<wire x1="25.4" y1="22.86" x2="5.08" y2="22.86" width="0.254" layer="94"/>
</symbol>
<symbol name="ENCODE">
<pin name="GND" x="15.24" y="15.24" length="middle" rot="R180"/>
<pin name="OUTB" x="15.24" y="12.7" length="middle" rot="R180"/>
<pin name="OUTA" x="15.24" y="10.16" length="middle" rot="R180"/>
<pin name="VCC" x="15.24" y="7.62" length="middle" rot="R180"/>
<pin name="M2" x="15.24" y="5.08" length="middle" rot="R180"/>
<pin name="M1" x="15.24" y="2.54" length="middle" rot="R180"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.254" layer="94"/>
<wire x1="10.16" y1="0" x2="10.16" y2="17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="17.78" x2="0" y2="17.78" width="0.254" layer="94"/>
<wire x1="0" y1="17.78" x2="0" y2="0" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VL6180" prefix="VL6180">
<gates>
<gate name="G$1" symbol="VL6180" x="0" y="0"/>
</gates>
<devices>
<device name="" package="VL6180">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GPIO" pad="GPIO"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="XSHUT" pad="XSHUT"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ESP32" prefix="ESP32">
<gates>
<gate name="G$1" symbol="ESP32" x="0" y="2.54"/>
</gates>
<devices>
<device name="" package="ESP32">
<connects>
<connect gate="G$1" pin="12/A11" pad="12/A11"/>
<connect gate="G$1" pin="13/A12" pad="13/A12"/>
<connect gate="G$1" pin="14/A6" pad="14/A6"/>
<connect gate="G$1" pin="15/A8" pad="15/A8"/>
<connect gate="G$1" pin="21" pad="21"/>
<connect gate="G$1" pin="27/A10" pad="27/A10"/>
<connect gate="G$1" pin="32/A7" pad="32/A7"/>
<connect gate="G$1" pin="33/A9" pad="33/A9"/>
<connect gate="G$1" pin="3V" pad="3V"/>
<connect gate="G$1" pin="A0/DAC2" pad="A0/DAC2"/>
<connect gate="G$1" pin="A1/DAC1" pad="A1/DAC1"/>
<connect gate="G$1" pin="A2/34" pad="A2/34"/>
<connect gate="G$1" pin="A3/39" pad="A3/39"/>
<connect gate="G$1" pin="A4/36" pad="A4/36"/>
<connect gate="G$1" pin="A5/4" pad="A5/4"/>
<connect gate="G$1" pin="BAT" pad="BAT"/>
<connect gate="G$1" pin="EN" pad="EN"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="MISO/19" pad="MISO/19"/>
<connect gate="G$1" pin="MOSI/18" pad="MOSI/18"/>
<connect gate="G$1" pin="NC" pad="NC"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RX/16" pad="RX/16"/>
<connect gate="G$1" pin="SCK/5" pad="SCK/5"/>
<connect gate="G$1" pin="SCL/22" pad="SCL/22"/>
<connect gate="G$1" pin="SDA/23" pad="SDA/23"/>
<connect gate="G$1" pin="TX/17" pad="TX/17"/>
<connect gate="G$1" pin="USB" pad="USB"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="12VBOOST" prefix="12VBOOST">
<gates>
<gate name="G$1" symbol="12VBOOST" x="0" y="0"/>
</gates>
<devices>
<device name="" package="12VBOOST">
<connects>
<connect gate="G$1" pin="GNDI" pad="GNDI"/>
<connect gate="G$1" pin="GNDO" pad="GNDO"/>
<connect gate="G$1" pin="VI" pad="VI"/>
<connect gate="G$1" pin="VO" pad="VO"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOTOR" prefix="MOTOR">
<gates>
<gate name="G$1" symbol="MOTOR" x="-5.08" y="0"/>
</gates>
<devices>
<device name="" package="MOTOR">
<connects>
<connect gate="G$1" pin="A01" pad="A01"/>
<connect gate="G$1" pin="A02" pad="A02"/>
<connect gate="G$1" pin="AIN1" pad="AIN1"/>
<connect gate="G$1" pin="AIN2" pad="AIN2"/>
<connect gate="G$1" pin="B01" pad="B01"/>
<connect gate="G$1" pin="B02" pad="B02"/>
<connect gate="G$1" pin="BIN1" pad="BIN1"/>
<connect gate="G$1" pin="BIN2" pad="BIN2"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="PWMA" pad="PWMA"/>
<connect gate="G$1" pin="PWMB" pad="PWMB"/>
<connect gate="G$1" pin="STBY" pad="STBY"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VMOT" pad="VMOT"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ENCODE" prefix="ENCODE">
<gates>
<gate name="G$1" symbol="ENCODE" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ENCODE">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="M1" pad="M1"/>
<connect gate="G$1" pin="M2" pad="M2"/>
<connect gate="G$1" pin="OUTA" pad="OUTA"/>
<connect gate="G$1" pin="OUTB" pad="OUTB"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0.4064" drill="0.508">
<clearance class="0" value="0.254"/>
</class>
<class number="1" name="12V" width="0.6096" drill="0.508">
<clearance class="0" value="0.4064"/>
<clearance class="1" value="0.4064"/>
</class>
</classes>
<parts>
<part name="VL_21" library="micromouse" deviceset="VL6180" device=""/>
<part name="ESP1" library="micromouse" deviceset="ESP32" device=""/>
<part name="12VBOOST1" library="micromouse" deviceset="12VBOOST" device=""/>
<part name="VL_A5" library="micromouse" deviceset="VL6180" device=""/>
<part name="VL_27" library="micromouse" deviceset="VL6180" device=""/>
<part name="MOTOR1" library="micromouse" deviceset="MOTOR" device=""/>
<part name="ENCODE_A2" library="micromouse" deviceset="ENCODE" device=""/>
<part name="ENCODE_A3" library="micromouse" deviceset="ENCODE" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="VL_21" gate="G$1" x="-30.48" y="83.82" smashed="yes"/>
<instance part="ESP1" gate="G$1" x="35.56" y="33.02" smashed="yes"/>
<instance part="12VBOOST1" gate="G$1" x="-45.72" y="38.1" smashed="yes"/>
<instance part="VL_A5" gate="G$1" x="35.56" y="121.92" smashed="yes" rot="R270"/>
<instance part="VL_27" gate="G$1" x="127" y="101.6" smashed="yes" rot="R180"/>
<instance part="MOTOR1" gate="G$1" x="38.1" y="-2.54" smashed="yes"/>
<instance part="ENCODE_A2" gate="G$1" x="-45.72" y="7.62" smashed="yes"/>
<instance part="ENCODE_A3" gate="G$1" x="-45.72" y="-12.7" smashed="yes"/>
<instance part="GND1" gate="1" x="-27.94" y="27.94" smashed="yes" rot="R180">
<attribute name="VALUE" x="-25.4" y="30.48" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND2" gate="1" x="-27.94" y="7.62" smashed="yes" rot="R180">
<attribute name="VALUE" x="-25.4" y="10.16" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND3" gate="1" x="17.78" y="63.5" smashed="yes" rot="R270">
<attribute name="VALUE" x="15.24" y="66.04" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND4" gate="1" x="-2.54" y="96.52" smashed="yes" rot="R90">
<attribute name="VALUE" x="0" y="93.98" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND5" gate="1" x="48.26" y="93.98" smashed="yes">
<attribute name="VALUE" x="45.72" y="91.44" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="106.68" y="88.9" smashed="yes" rot="R270">
<attribute name="VALUE" x="104.14" y="91.44" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND7" gate="1" x="-12.7" y="50.8" smashed="yes" rot="R180">
<attribute name="VALUE" x="-10.16" y="53.34" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND8" gate="1" x="71.12" y="-5.08" smashed="yes">
<attribute name="VALUE" x="68.58" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="GND9" gate="1" x="33.02" y="17.78" smashed="yes" rot="R270">
<attribute name="VALUE" x="30.48" y="20.32" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND10" gate="1" x="33.02" y="0" smashed="yes" rot="R270">
<attribute name="VALUE" x="30.48" y="2.54" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND11" gate="1" x="-12.7" y="38.1" smashed="yes">
<attribute name="VALUE" x="-15.24" y="35.56" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
<bus name="I2C:SCL,SDA">
<segment>
<wire x1="78.74" y1="33.02" x2="78.74" y2="93.98" width="0.762" layer="92"/>
<wire x1="78.74" y1="93.98" x2="106.68" y2="93.98" width="0.762" layer="92"/>
<wire x1="78.74" y1="93.98" x2="43.18" y2="93.98" width="0.762" layer="92"/>
<wire x1="43.18" y1="93.98" x2="43.18" y2="101.6" width="0.762" layer="92"/>
<wire x1="43.18" y1="93.98" x2="-10.16" y2="93.98" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="MA:MA1,MA2">
<segment>
<wire x1="33.02" y1="10.16" x2="-22.86" y2="10.16" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="MB:MB1,MB2">
<segment>
<wire x1="33.02" y1="5.08" x2="-15.24" y2="5.08" width="0.762" layer="92"/>
<wire x1="-15.24" y1="5.08" x2="-15.24" y2="-10.16" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="PWM:PWMA,PWMB">
<segment>
<wire x1="22.86" y1="60.96" x2="22.86" y2="25.4" width="0.762" layer="92"/>
<wire x1="22.86" y1="25.4" x2="78.74" y2="25.4" width="0.762" layer="92"/>
<wire x1="78.74" y1="25.4" x2="78.74" y2="2.54" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="MOTOR:AIN[1..2],BIN[1..2]">
<segment>
<wire x1="73.66" y1="45.72" x2="73.66" y2="5.08" width="0.762" layer="92"/>
</segment>
</bus>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="ENCODE_A2" gate="G$1" pin="GND"/>
<wire x1="-30.48" y1="22.86" x2="-27.94" y2="22.86" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="-27.94" y1="22.86" x2="-27.94" y2="25.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ENCODE_A3" gate="G$1" pin="GND"/>
<wire x1="-30.48" y1="2.54" x2="-27.94" y2="2.54" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="-27.94" y1="2.54" x2="-27.94" y2="5.08" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_21" gate="G$1" pin="GND"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="-5.08" y1="96.52" x2="-15.24" y2="96.52" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_A5" gate="G$1" pin="GND"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="48.26" y1="96.52" x2="48.26" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_27" gate="G$1" pin="GND"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="109.22" y1="88.9" x2="111.76" y2="88.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ESP1" gate="G$1" pin="GND"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="30.48" y1="63.5" x2="20.32" y2="63.5" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="GND1"/>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="35.56" y1="17.78" x2="38.1" y2="17.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="GND2"/>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="35.56" y1="0" x2="38.1" y2="0" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="12VBOOST1" gate="G$1" pin="GNDI"/>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="-30.48" y1="45.72" x2="-12.7" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-12.7" y1="45.72" x2="-12.7" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="12VBOOST1" gate="G$1" pin="GNDO"/>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="-30.48" y1="43.18" x2="-12.7" y2="43.18" width="0.1524" layer="91"/>
<wire x1="-12.7" y1="43.18" x2="-12.7" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="GND"/>
<wire x1="68.58" y1="0" x2="71.12" y2="0" width="0.1524" layer="91"/>
<pinref part="GND8" gate="1" pin="GND"/>
<wire x1="71.12" y1="0" x2="71.12" y2="-2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="BOOST_OUT" class="1">
<segment>
<pinref part="12VBOOST1" gate="G$1" pin="VO"/>
<wire x1="-30.48" y1="40.64" x2="-17.78" y2="40.64" width="0.1524" layer="91"/>
<pinref part="MOTOR1" gate="G$1" pin="VMOT"/>
<wire x1="-17.78" y1="40.64" x2="-17.78" y2="2.54" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="2.54" x2="38.1" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="3V"/>
<wire x1="30.48" y1="68.58" x2="27.94" y2="68.58" width="0.1524" layer="91"/>
<label x="27.94" y="68.58" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="VL_21" gate="G$1" pin="VIN"/>
<wire x1="-15.24" y1="99.06" x2="-12.7" y2="99.06" width="0.1524" layer="91"/>
<label x="-12.7" y="99.06" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="VL_A5" gate="G$1" pin="VIN"/>
<wire x1="50.8" y1="106.68" x2="50.8" y2="104.14" width="0.1524" layer="91"/>
<label x="50.8" y="104.14" size="1.778" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="VL_27" gate="G$1" pin="VIN"/>
<wire x1="111.76" y1="86.36" x2="101.6" y2="86.36" width="0.1524" layer="91"/>
<label x="101.6" y="86.36" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="VCC"/>
<wire x1="38.1" y1="15.24" x2="27.94" y2="15.24" width="0.1524" layer="91"/>
<label x="27.94" y="15.24" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="ENCODE_A2" gate="G$1" pin="VCC"/>
<wire x1="-30.48" y1="15.24" x2="-27.94" y2="15.24" width="0.1524" layer="91"/>
<label x="-27.94" y="15.24" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="ENCODE_A3" gate="G$1" pin="VCC"/>
<wire x1="-30.48" y1="-5.08" x2="-27.94" y2="-5.08" width="0.1524" layer="91"/>
<label x="-27.94" y="-5.08" size="1.778" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="13/A12"/>
<wire x1="63.5" y1="53.34" x2="88.9" y2="53.34" width="0.1524" layer="91"/>
<wire x1="88.9" y1="53.34" x2="88.9" y2="10.16" width="0.1524" layer="91"/>
<pinref part="MOTOR1" gate="G$1" pin="STBY"/>
<wire x1="88.9" y1="10.16" x2="68.58" y2="10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="ENCODE_A2" gate="G$1" pin="OUTA"/>
<wire x1="-30.48" y1="17.78" x2="10.16" y2="17.78" width="0.1524" layer="91"/>
<wire x1="10.16" y1="17.78" x2="10.16" y2="55.88" width="0.1524" layer="91"/>
<pinref part="ESP1" gate="G$1" pin="A2/34"/>
<wire x1="10.16" y1="55.88" x2="30.48" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="ENCODE_A3" gate="G$1" pin="OUTA"/>
<wire x1="-30.48" y1="-2.54" x2="12.7" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-2.54" x2="12.7" y2="53.34" width="0.1524" layer="91"/>
<pinref part="ESP1" gate="G$1" pin="A3/39"/>
<wire x1="12.7" y1="53.34" x2="30.48" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="BOOST_IN" class="1">
<segment>
<pinref part="ESP1" gate="G$1" pin="BAT"/>
<wire x1="63.5" y1="60.96" x2="66.04" y2="60.96" width="0.1524" layer="91"/>
<wire x1="66.04" y1="60.96" x2="66.04" y2="78.74" width="0.1524" layer="91"/>
<wire x1="66.04" y1="78.74" x2="-27.94" y2="78.74" width="0.1524" layer="91"/>
<pinref part="12VBOOST1" gate="G$1" pin="VI"/>
<wire x1="-30.48" y1="48.26" x2="-27.94" y2="48.26" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="48.26" x2="-27.94" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="27/A10"/>
<wire x1="63.5" y1="48.26" x2="81.28" y2="48.26" width="0.1524" layer="91"/>
<wire x1="81.28" y1="48.26" x2="81.28" y2="99.06" width="0.1524" layer="91"/>
<pinref part="VL_27" gate="G$1" pin="XSHUT"/>
<wire x1="81.28" y1="99.06" x2="111.76" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="VL_21" gate="G$1" pin="XSHUT"/>
<wire x1="-15.24" y1="86.36" x2="0" y2="86.36" width="0.1524" layer="91"/>
<wire x1="0" y1="86.36" x2="0" y2="33.02" width="0.1524" layer="91"/>
<pinref part="ESP1" gate="G$1" pin="21"/>
<wire x1="0" y1="33.02" x2="30.48" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="A5/4"/>
<wire x1="30.48" y1="48.26" x2="2.54" y2="48.26" width="0.1524" layer="91"/>
<wire x1="2.54" y1="48.26" x2="2.54" y2="99.06" width="0.1524" layer="91"/>
<wire x1="2.54" y1="99.06" x2="38.1" y2="99.06" width="0.1524" layer="91"/>
<pinref part="VL_A5" gate="G$1" pin="XSHUT"/>
<wire x1="38.1" y1="99.06" x2="38.1" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<pinref part="VL_21" gate="G$1" pin="SCL"/>
<wire x1="-10.16" y1="93.98" x2="-15.24" y2="93.98" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_A5" gate="G$1" pin="SCL"/>
<wire x1="43.18" y1="99.06" x2="45.72" y2="99.06" width="0.1524" layer="91"/>
<wire x1="45.72" y1="99.06" x2="45.72" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_27" gate="G$1" pin="SCL"/>
<wire x1="104.14" y1="93.98" x2="104.14" y2="91.44" width="0.1524" layer="91"/>
<wire x1="104.14" y1="91.44" x2="111.76" y2="91.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ESP1" gate="G$1" pin="SCL/22"/>
<wire x1="78.74" y1="35.56" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<pinref part="VL_21" gate="G$1" pin="SDA"/>
<wire x1="-7.62" y1="93.98" x2="-7.62" y2="91.44" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="91.44" x2="-15.24" y2="91.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_A5" gate="G$1" pin="SDA"/>
<wire x1="43.18" y1="101.6" x2="43.18" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VL_27" gate="G$1" pin="SDA"/>
<wire x1="106.68" y1="93.98" x2="111.76" y2="93.98" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ESP1" gate="G$1" pin="SDA/23"/>
<wire x1="78.74" y1="33.02" x2="63.5" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MA2" class="1">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="A02"/>
<wire x1="33.02" y1="10.16" x2="38.1" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ENCODE_A2" gate="G$1" pin="M2"/>
<wire x1="-20.32" y1="10.16" x2="-20.32" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="12.7" x2="-30.48" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MA1" class="1">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="A01"/>
<wire x1="30.48" y1="10.16" x2="30.48" y2="12.7" width="0.1524" layer="91"/>
<wire x1="30.48" y1="12.7" x2="38.1" y2="12.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ENCODE_A2" gate="G$1" pin="M1"/>
<wire x1="-22.86" y1="10.16" x2="-30.48" y2="10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MB1" class="1">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="B01"/>
<wire x1="33.02" y1="5.08" x2="38.1" y2="5.08" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ENCODE_A3" gate="G$1" pin="M1"/>
<wire x1="-15.24" y1="-10.16" x2="-30.48" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MB2" class="1">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="B02"/>
<wire x1="30.48" y1="5.08" x2="30.48" y2="7.62" width="0.1524" layer="91"/>
<wire x1="30.48" y1="7.62" x2="38.1" y2="7.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ENCODE_A3" gate="G$1" pin="M2"/>
<wire x1="-15.24" y1="-7.62" x2="-30.48" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PWMA" class="0">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="PWMA"/>
<wire x1="78.74" y1="17.78" x2="68.58" y2="17.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ESP1" gate="G$1" pin="A1/DAC1"/>
<wire x1="22.86" y1="58.42" x2="30.48" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PWMB" class="0">
<segment>
<pinref part="MOTOR1" gate="G$1" pin="PWMB"/>
<wire x1="78.74" y1="2.54" x2="68.58" y2="2.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ESP1" gate="G$1" pin="A0/DAC2"/>
<wire x1="22.86" y1="60.96" x2="30.48" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AIN1" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="33/A9"/>
<wire x1="73.66" y1="45.72" x2="63.5" y2="45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="AIN1"/>
<wire x1="73.66" y1="12.7" x2="68.58" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AIN2" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="15/A8"/>
<wire x1="73.66" y1="43.18" x2="63.5" y2="43.18" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="AIN2"/>
<wire x1="73.66" y1="15.24" x2="68.58" y2="15.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="BIN1" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="32/A7"/>
<wire x1="73.66" y1="40.64" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="BIN1"/>
<wire x1="73.66" y1="7.62" x2="68.58" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="BIN2" class="0">
<segment>
<pinref part="ESP1" gate="G$1" pin="14/A6"/>
<wire x1="73.66" y1="38.1" x2="63.5" y2="38.1" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MOTOR1" gate="G$1" pin="BIN2"/>
<wire x1="73.66" y1="5.08" x2="68.58" y2="5.08" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
