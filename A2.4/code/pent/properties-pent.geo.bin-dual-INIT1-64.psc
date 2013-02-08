<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>19:49:11</time>
  <numProcs>64</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="1" thread="0"/>
		<execObj process="0" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="28" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="32" thread="0"/>
		<execObj process="36" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="41" thread="0"/>
		<execObj process="33" thread="0"/>
		<execObj process="37" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="42" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="35" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="44" thread="0"/>
		<execObj process="52" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="57" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="56" thread="0"/>
		<execObj process="8" thread="0"/>
		<execObj process="12" thread="0"/>
		<execObj process="5" thread="0"/>
		<execObj process="9" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="10" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>8.70285</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="49" thread="0"/>
	</context>
	<severity>6.31064</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>139155</CallTime>
		<PhaseTime>2205085</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="17" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="28" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="32" thread="0"/>
		<execObj process="36" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="41" thread="0"/>
		<execObj process="33" thread="0"/>
		<execObj process="37" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="42" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="35" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="44" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="0" thread="0"/>
		<execObj process="52" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="57" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="56" thread="0"/>
		<execObj process="8" thread="0"/>
		<execObj process="12" thread="0"/>
		<execObj process="5" thread="0"/>
		<execObj process="9" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="10" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>8.68547</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="49" thread="0"/>
	</context>
	<severity>6.30094</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>139155</CallTime>
		<LateTime>138941</LateTime>
		<PhaseTime>2205085</PhaseTime>
	</addInfo>
  </property>
</Experiment>
