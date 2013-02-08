<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>19:58:25</time>
  <numProcs>64</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="44" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="32" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="12" thread="0"/>
	</context>
	<severity>70.046</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="9" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="36" thread="0"/>
	</context>
	<severity>76.1266</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="26" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="0" thread="0"/>
	</context>
	<severity>57.5493</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
		<execObj process="28" thread="0"/>
	</context>
	<severity>77.9723</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="30" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="48" thread="0"/>
		<execObj process="49" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>65.1505</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="19" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="36" thread="0"/>
	</context>
	<severity>75.0735</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="12" thread="0"/>
	</context>
	<severity>24.9325</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="28" thread="0"/>
	</context>
	<severity>77.9834</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>188404</CallTime>
		<LateTime>925011</LateTime>
		<PhaseTime>241595</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="52" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="56" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="44" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="32" thread="0"/>
	</context>
	<severity>68.8666</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>11.5989</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>137313</CallTime>
		<LateTime>28024</LateTime>
		<PhaseTime>241609</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="42" thread="0"/>
		<execObj process="16" thread="0"/>
	</context>
	<severity>59.2466</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="17" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="52" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="56" thread="0"/>
	</context>
	<severity>67.9168</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="8" thread="0"/>
	</context>
	<severity>49.9431</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>120664</CallTime>
		<PhaseTime>241603</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="53" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="48" thread="0"/>
		<execObj process="37" thread="0"/>
		<execObj process="49" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="20" thread="0"/>
	</context>
	<severity>64.7871</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="28" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="28" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="32" thread="0"/>
		<execObj process="5" thread="0"/>
		<execObj process="9" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="9" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="36" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="41" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="41" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="38" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="36" thread="0"/>
	</context>
	<severity>6.68752</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="4" thread="0"/>
	</context>
	<severity>21.5964</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>159404</CallTime>
		<LateTime>52177</LateTime>
		<PhaseTime>241601</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="12" thread="0"/>
		<execObj process="4" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="11" thread="0"/>
		<execObj process="12" thread="0"/>
		<execObj process="56" thread="0"/>
		<execObj process="52" thread="0"/>
		<execObj process="48" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="49" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="61" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="56" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="48" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="49" thread="0"/>
		<execObj process="57" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="52" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="44" thread="0"/>
		<execObj process="40" thread="0"/>
		<execObj process="44" thread="0"/>
		<execObj process="37" thread="0"/>
		<execObj process="37" thread="0"/>
		<execObj process="33" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="35" thread="0"/>
		<execObj process="43" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="32" thread="0"/>
	</context>
	<severity>9.42981</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="20" thread="0"/>
		<execObj process="16" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="16" thread="0"/>
		<execObj process="42" thread="0"/>
		<execObj process="8" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="0" thread="0"/>
	</context>
	<severity>13.9747</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="42" thread="0"/>
		<execObj process="16" thread="0"/>
	</context>
	<severity>58.7959</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="10" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="33" thread="0"/>
		<execObj process="37" thread="0"/>
	</context>
	<severity>63.2391</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="27" thread="0"/>
		<execObj process="8" thread="0"/>
	</context>
	<severity>16.8368</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="42" thread="0"/>
		<execObj process="35" thread="0"/>
		<execObj process="33" thread="0"/>
		<execObj process="57" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="0" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="10" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="10" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>11.9186</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="17" thread="0"/>
		<execObj process="24" thread="0"/>
		<execObj process="48" thread="0"/>
		<execObj process="53" thread="0"/>
		<execObj process="54" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="56" thread="0"/>
	</context>
	<severity>9.83201</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="50" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="57" thread="0"/>
		<execObj process="58" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="35" thread="0"/>
		<execObj process="33" thread="0"/>
	</context>
	<severity>62.4246</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="35" thread="0"/>
		<execObj process="50" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="57" thread="0"/>
	</context>
	<severity>61.7284</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="7" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="59" thread="0"/>
		<execObj process="41" thread="0"/>
	</context>
	<severity>73.3573</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="13" thread="0"/>
	</context>
	<severity>19.8865</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>158266</CallTime>
		<LateTime>48046</LateTime>
		<PhaseTime>241601</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="57" thread="0"/>
		<execObj process="62" thread="0"/>
		<execObj process="55" thread="0"/>
		<execObj process="51" thread="0"/>
		<execObj process="63" thread="0"/>
		<execObj process="60" thread="0"/>
		<execObj process="16" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="20" thread="0"/>
	</context>
	<severity>13.117</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="22" thread="0"/>
		<execObj process="34" thread="0"/>
		<execObj process="39" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="41" thread="0"/>
	</context>
	<severity>71.8434</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="7" thread="0"/>
		<execObj process="9" thread="0"/>
	</context>
	<severity>30.1749</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
	</context>
	<severity>33.633</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>188351</CallTime>
		<LateTime>81256</LateTime>
		<PhaseTime>241596</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="6" thread="0"/>
	</context>
	<severity>13.69</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>138363</CallTime>
		<LateTime>33075</LateTime>
		<PhaseTime>241599</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="47" thread="0"/>
	</context>
	<severity>5.81465</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>26057</CallTime>
		<LateTime>14049</LateTime>
		<PhaseTime>241614</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
		<execObj process="2" thread="0"/>
	</context>
	<severity>27.7924</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="62" thread="0"/>
		<execObj process="26" thread="0"/>
	</context>
	<severity>57.7983</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="10" thread="0"/>
	</context>
	<severity>17.9398</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>152447</CallTime>
		<LateTime>43343</LateTime>
		<PhaseTime>241602</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="59" thread="0"/>
	</context>
	<severity>73.5211</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>177624</CallTime>
		<LateTime>972300</LateTime>
		<PhaseTime>241596</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="64x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="27" thread="0"/>
	</context>
	<severity>16.6006</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>40107</CallTime>
		<LateTime>413166</LateTime>
		<PhaseTime>241599</PhaseTime>
	</addInfo>
  </property>
</Experiment>
