package com.ftdichip.ftd2xx;

/**
 * Enumeration of all possible <i>Bit Bang Modes</i>.
 * 
 * @author Mike Werner
 */
public enum BitBangMode {

	/**
	 * Resets the I/O <i>Bit Bang </i> mode.
	 */
	RESET(0x0),

	/**
	 * Asynchronous <i>Bit Bang Mode </i>.
	 */
	ASYNCHRONOUS(0x1),

	/**
	 * <i>MPSSE </i> mode.
	 */
	MPSSE(0x2),

	/**
	 * Synchronous <i>Bit Bang Mode </i>
	 */
	SYNCHRONOUS(0x4),

	/**
	 * <i>MCU </i> host bus emulation mode.
	 */
	MCU_HOST_BUS_EMULATION(0x8),

	/**
	 * Fast opto-isolated serial mode.
	 */
	FAST_OPTO_ISOLATED_SERIAL(0x10),

	/**
	 * Constant if the mode is unknown.
	 */
	UNKNOWN(-1);

	/**
	 * Holds the native value of a particular {@code BitBangMode}.
	 */
	public final int value;

	private BitBangMode(int value) {

		this.value = value;
	}

	/**
	 * Retrieves the {@code BitBangMode} by it`s native mode value.
	 * 
	 * @param mode
	 *            the native mode value.
	 * @return the enumeration constant representing the mode value,
	 *         {@link #UNKNOWN} fi the native value can not be represented by
	 *         this enumeration..
	 */
	public static BitBangMode valueOf(int mode) throws FTD2xxException {

		BitBangMode result = UNKNOWN;

		for (BitBangMode m : values()) {
			if (m.value == mode) {
				result = m;
				break;
			}
		}

		return result;
	}
}
