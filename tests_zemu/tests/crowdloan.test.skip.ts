/** ******************************************************************************
 * (c) 2018 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************* */

import Zemu from '@zondax/zemu'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import { defaultOptions, models } from './common'

jest.setTimeout(60000)

describe('Crowdloan', function () {
  test.concurrent.each(models)('crowdloan menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(), 'Kusama')

      const kusama_expected_address = 'JMdbWK5cy3Bm4oCyhWNLQJoC4cczNgJsyk7nLZHMqFT7z7R'
      const kusama_expected_pk = 'ffbc10f71d63e0da1b9e7ee2eb4037466551dc32b9d4641aafd73a65970fae42'
      const polkadot_expected_address = 'gpu3f9qB4W1XU2QSrs7thH3oRsMtZoycYrtwQdJwwwuicZe'
      const polkadot_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(kusama_expected_address)
      expect(resp.pubKey).toEqual(kusama_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      await sim.enableSpecialMode('Account')

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(polkadot_expected_address)
      expect(resp.pubKey).toEqual(polkadot_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
    } finally {
      await sim.close()
    }
  })
})
