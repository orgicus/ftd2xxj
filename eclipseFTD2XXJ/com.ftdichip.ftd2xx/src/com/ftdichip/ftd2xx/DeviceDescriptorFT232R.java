package com.ftdichip.ftd2xx;

/**
 * Extends the <code>DeviceDescriptor</code> with new fields available for
 * FT232R devices.<br>
 * <br>
 * <b>For a more detailed description of the fields see the ftd2xx-API
 * specification. </b>
 * 
 * @author Mike Werner
 */
public class DeviceDescriptorFT232R extends DeviceDescriptor {
	/**
	 * {@code true} if using an external oscillator, {@code false} otherwise.
	 */
	private boolean useExternalOscillator;

	/**
	 * {@code true} if high drive I/O's, {@code false} otherwise.
	 */
	private boolean highDriveIOs;

	/**
	 * Endpoint size
	 */
	private int endPointSize;

	/**
	 * {@code true} if pullDown enabled, {@code false} otherwise.
	 */
	private boolean pullDownEnabled;

	/**
	 * {@code true} if the serialNumber shall be used, {@code false}otherwise.
	 */
	private boolean serialNumberEnabled;

	/**
	 * {@code true} if invert TXD
	 */
	private boolean invertTXD;

	/**
	 * {@code true}if invert RXD
	 */
	private boolean invertRXD;

	/**
	 * {@code true} if invert RTS
	 */
	private boolean invertRTS;

	/**
	 * {@code true} if invert CTS
	 */
	private boolean invertCTS;

	/**
	 * {@code true} if invert DTR
	 */
	private boolean invertDTR;

	/**
	 * {@code true} if invert DSR
	 */
	private boolean invertDSR;

	/**
	 * {@code true} if invert DCD
	 */
	private boolean invertDCD;

	/**
	 * {@code true} if invert RI
	 */
	private boolean invertRI;

	/**
	 * Cbus Mux control
	 */
	private int cbus0;

	/**
	 * Cbus Mux control
	 */
	private int cbus1;

	/**
	 * Cbus Mux control
	 */
	private int cbus2;

	/**
	 * Cbus Mux control
	 */
	private int cbus3;

	/**
	 * Cbus Mux control
	 */
	private int cbus4;

	/**
	 * {@code true} if using D2XX drivers.
	 */
	private boolean interfaceUseD2xxDrivers;

	/**
	 * Determines whether an external oscillator is used or not.
	 * 
	 * @return {@code true} if an external oscillator is used, {@code false}
	 *         otherwise.
	 */
	public boolean isUseExternalOscillator() {
		return useExternalOscillator;
	}

	/**
	 * Sets the new value of {@code useExternalOscillator}.
	 * 
	 * @param useExternalOscillator
	 *            if {@code true} an external oscillator is used, if {@code
	 *            false} not.
	 */
	public void setUseExternalOscillator(boolean useExternalOscillator) {
		this.useExternalOscillator = useExternalOscillator;
	}

	/**
	 * Determines whether High Drive I/Os is used or not.
	 * 
	 * @return {@code true} if High Drive I/Os is used, otherwise {@code false}.
	 */
	public boolean isHighDriveIOs() {
		return highDriveIOs;
	}

	/**
	 * Sets the new value of {@code highDriveIOs}.
	 * 
	 * @param highDriveIOs
	 *            the new value.
	 */
	public void setHighDriveIOs(boolean highDriveIOs) {
		this.highDriveIOs = highDriveIOs;
	}

	/**
	 * Retrieves the end point size.
	 * 
	 * @return the endPointSize.
	 */
	public int getEndPointSize() {
		return endPointSize;
	}

	/**
	 * Sets the new end point size.
	 * 
	 * @param endPointSize
	 *            the new endPointSize.
	 */
	public void setEndPointSize(int endPointSize) {
		this.endPointSize = endPointSize;
	}

	/**
	 * Determines whether pull down is enabled or not.
	 * 
	 * @return {@code true} if pull down is enabled, otherwise {@code false}.
	 */
	public boolean isPullDownEnabled() {
		return pullDownEnabled;
	}

	/**
	 * Sets the new value of {@code pullDownEnabled}.
	 * 
	 * @param pullDownEnabled
	 *            the new value.
	 */
	public void setPullDownEnabled(boolean pullDownEnabled) {
		this.pullDownEnabled = pullDownEnabled;
	}

	/**
	 * Determines whether the serial number is enabled or not.
	 * 
	 * @return {@code true} if the serial number is enabled, {@code false}
	 *         otherwise.
	 */
	public boolean isSerialNumberEnabled() {
		return serialNumberEnabled;
	}

	/**
	 * Sets the new value of {@code serialNumberEnabled}.
	 * 
	 * @param serialNumberEnabled
	 *            the new value.
	 */
	public void setSerialNumberEnabled(boolean serialNumberEnabled) {
		this.serialNumberEnabled = serialNumberEnabled;
	}

	/**
	 * Determines whether TXD is inverted or not.
	 * 
	 * @return {@code true} if TXD is inverted, otherwise {@code false}.
	 */
	public boolean isInvertTXD() {
		return invertTXD;
	}

	/**
	 * Sets the new value of invertTXD.
	 * 
	 * @param invertTXD
	 *            the new value.
	 */
	public void setInvertTXD(boolean invertTXD) {
		this.invertTXD = invertTXD;
	}

	/**
	 * Determines whether RXD is inverted or not.
	 * 
	 * @return {@code true} if RXD is inverted, otherwise {@code false}.
	 */
	public boolean isInvertRXD() {
		return invertRXD;
	}

	/**
	 * Sets the new value of invertRXD.
	 * 
	 * @param invertRXD
	 *            the new value.
	 */
	public void setInvertRXD(boolean invertRXD) {
		this.invertRXD = invertRXD;
	}

	/**
	 * Determines whether RTS is inverted or not.
	 * 
	 * @return {@code true} if RTS is inverted, otherwise {@code false}.
	 */
	public boolean isInvertRTS() {
		return invertRTS;
	}

	/**
	 * Sets the new value of invertRTS.
	 * 
	 * @param invertRTS
	 *            the new value.
	 */
	public void setInvertRTS(boolean invertRTS) {
		this.invertRTS = invertRTS;
	}

	/**
	 * Determines whether CTS is inverted or not.
	 * 
	 * @return {@code true} if CTS is inverted, otherwise {@code false}.
	 */
	public boolean isInvertCTS() {
		return invertCTS;
	}

	/**
	 * Sets the new value of invertCTS.
	 * 
	 * @param invertCTS
	 *            the new value.
	 */
	public void setInvertCTS(boolean invertCTS) {
		this.invertCTS = invertCTS;
	}

	/**
	 * Determines whether DTR is inverted or not.
	 * 
	 * @return {@code true} if DTR is inverted, otherwise {@code false}.
	 */
	public boolean isInvertDTR() {
		return invertDTR;
	}

	/**
	 * Sets the new value of invertDTR.
	 * 
	 * @param invertDTR
	 *            the new value.
	 */
	public void setInvertDTR(boolean invertDTR) {
		this.invertDTR = invertDTR;
	}

	/**
	 * Determines whether DSR is inverted or not.
	 * 
	 * @return {@code true} if DSR is inverted, otherwise {@code false}.
	 */
	public boolean isInvertDSR() {
		return invertDSR;
	}

	/**
	 * Sets the new value of invertDSR.
	 * 
	 * @param invertDSR
	 *            the new value.
	 */
	public void setInvertDSR(boolean invertDSR) {
		this.invertDSR = invertDSR;
	}

	/**
	 * Determines whether DCD is inverted or not.
	 * 
	 * @return {@code true} if DCD is inverted, otherwise {@code false}.
	 */
	public boolean isInvertDCD() {
		return invertDCD;
	}

	/**
	 * Sets the new value of invertDCD.
	 * 
	 * @param invertDCD
	 *            the new value.
	 */
	public void setInvertDCD(boolean invertDCD) {
		this.invertDCD = invertDCD;
	}

	/**
	 * Determines whether RI is inverted or not.
	 * 
	 * @return {@code true} if RI is inverted, otherwise {@code false}.
	 */
	public boolean isInvertRI() {
		return invertRI;
	}

	/**
	 * Sets the new value of invertRI.
	 * 
	 * @param invertRI
	 *            the new value.
	 */
	public void setInvertRI(boolean invertRI) {
		this.invertRI = invertRI;
	}

	/**
	 * Cbus Mux control - Ignored for FT245R
	 * 
	 * @return the {@link CBusOption}.
	 */
	public CBusOption getCbus0() {
		return CBusOption.valueOf(cbus0);
	}

	/**
	 * Sets the new value of cbus0.
	 * 
	 * @param value
	 *            the new value
	 */
	public void setCbus0(CBusOption value) {
		this.cbus0 = value.ordinal();
	}

	/**
	 * Cbus Mux control - Ignored for FT245R
	 * 
	 * @return the {@link CBusOption}.
	 */
	public CBusOption getCbus1() {
		return CBusOption.valueOf(cbus1);
	}

	/**
	 * Sets the new value of cbus1.
	 * 
	 * @param value
	 *            the new value.
	 */
	public void setCbus1(CBusOption value) {
		this.cbus1 = value.ordinal();
	}

	/**
	 * Cbus Mux control - Ignored for FT245R
	 * 
	 * @return the {@link CBusOption}.
	 */
	public CBusOption getCbus2() {
		return CBusOption.valueOf(cbus2);
	}

	/**
	 * Sets the new value of cbus2.
	 * 
	 * @param value
	 *            the new value.
	 */
	public void setCbus2(CBusOption value) {
		this.cbus2 = value.ordinal();
	}

	/**
	 * Cbus Mux control - Ignored for FT245R
	 * 
	 * @return the {@link CBusOption}.
	 */
	public CBusOption getCbus3() {
		return CBusOption.valueOf(cbus3);
	}

	/**
	 * Sets the new value of cbus3.
	 * 
	 * @param value
	 *            the new value.
	 */
	public void setCbus3(CBusOption value) {
		this.cbus3 = value.ordinal();
	}

	/**
	 * Cbus Mux control - Ignored for FT245R
	 * 
	 * @return the {@link CBusOption}.
	 */
	public CBusOption getCbus4() {
		return CBusOption.valueOf(cbus4);
	}

	/**
	 * Sets the new value of cbus4.
	 * 
	 * @param value
	 *            the new value.
	 */
	public void setCbus4(CBusOption value) {
		this.cbus4 = value.ordinal();
	}

	/**
	 * Determines whether the VCP drivers are used or not.
	 * 
	 * @return {@code true} if the VCP drivers are used, {@code false}
	 *         otherwise.
	 */
	public boolean isInterfaceUseD2xxDrivers() {
		return interfaceUseD2xxDrivers;
	}

	/**
	 * Sets the new value of interfaceUseD2xxDrivers.
	 * 
	 * @param interfaceUseD2xxDrivers
	 *            the new value.
	 */
	public void setInterfaceUseD2xxDrivers(boolean interfaceUseD2xxDrivers) {
		this.interfaceUseD2xxDrivers = interfaceUseD2xxDrivers;
	}
}
