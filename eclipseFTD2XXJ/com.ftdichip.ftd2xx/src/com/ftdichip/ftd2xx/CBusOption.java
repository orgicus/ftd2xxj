package com.ftdichip.ftd2xx;

/**
 * Enumeration of all CBus options. For more details see D2XX Programmers Guide.
 * 
 * @author Mike Werner
 */
public enum CBusOption {
	TXD_ENABLE, POWER_ON, RX_LED, TX_LED, TX_RX_LED, SLEEP, CLK_48, CLK_24,

	/**
	 * Used when the value of a cbus field is unknown.
	 */
	UNKNOWN;

	/**
	 * Retrieves the enumeration by it's native value.
	 * 
	 * @param value
	 *            the value for which to retrieve the enumeration constant.
	 * @return the enumeration constant which matches the {@code value}, {@code
	 *         CBusOption#UNKNOWN} if the value does not match any of the
	 *         enumeration constants.
	 */
	public static CBusOption valueOf(int value) {
		CBusOption result = UNKNOWN;

		for (CBusOption o : values()) {
			if (o.ordinal() == value) {
				result = o;
				break;
			}
		}

		return result;
	}
}
