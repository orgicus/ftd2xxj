import com.ftdichip.ftd2xx.Device;
import com.ftdichip.ftd2xx.DeviceType;
import com.ftdichip.ftd2xx.FTD2xxException;
import com.ftdichip.ftd2xx.Service;


public class FTD2XXJTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			//Device[] devices = Service.listDevicesByType(DeviceType.FT_DEVICE_UNKNOWN);
			Device[] devices = Service.listDevices();
			for (int i = 0; i < devices.length; i++) {
				System.out.println(devices[i]);
			}
		} catch (FTD2xxException e) {
			e.printStackTrace();
		}
	}

}
