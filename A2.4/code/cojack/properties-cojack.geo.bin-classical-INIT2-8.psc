<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>21:57:51</time>
  <numProcs>8</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>12.1934</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>19.9725</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>3018621</CallTime>
		<PhaseTime>15113877</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>11.8515</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>19.6293</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>3018621</CallTime>
		<LateTime>2966746</LateTime>
		<PhaseTime>15113877</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
		<execObj process="5" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>24.3728</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>39.9027</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>30.3679</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>4589770</CallTime>
		<PhaseTime>15113877</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
	</context>
	<severity>10.3544</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1564944</CallTime>
		<PhaseTime>15113872</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
	</context>
	<severity>10.0112</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1564944</CallTime>
		<LateTime>1513084</LateTime>
		<PhaseTime>15113872</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
	</context>
	<severity>42.6466</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>6445560</CallTime>
		<PhaseTime>15113872</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="6" thread="0"/>
	</context>
	<severity>8.34924</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1261894</CallTime>
		<PhaseTime>15113875</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="6" thread="0"/>
	</context>
	<severity>8.0076</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1261894</CallTime>
		<LateTime>1210259</LateTime>
		<PhaseTime>15113875</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="6" thread="0"/>
	</context>
	<severity>45.0093</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>6802653</CallTime>
		<PhaseTime>15113875</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>38.6997</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>5849027</CallTime>
		<PhaseTime>15113874</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>14.3559</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2169737</CallTime>
		<PhaseTime>15113874</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>14.0148</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2169737</CallTime>
		<LateTime>2118177</LateTime>
		<PhaseTime>15113874</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>36.5585</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>5525401</CallTime>
		<PhaseTime>15113874</PhaseTime>
	</addInfo>
  </property>
</Experiment>
